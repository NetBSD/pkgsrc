#==========================================================================
# When files are read in by pkglint, they are interpreted in terms of
# lines. For Makefiles, line continuations are handled properly, allowing
# multiple physical lines to end in a single logical line. For other files
# there is a 1:1 translation.
#
# A difference between the physical and the logical lines is that the
# physical lines include the line end sequence, whereas the logical lines
# do not.
#
# A logical line is a class having the read-only fields C<file>,
# C<lines>, C<text>, C<physlines> and C<is_changed>, as well as some
# methods for printing diagnostics easily.
#
# Some other methods allow modification of the physical lines, but leave
# the logical line (the C<text>) untouched. These methods are used in the
# --autofix mode.
#
# A line can have some "extra" fields that allow the results of parsing to
# be saved under a name.
#==========================================================================
package PkgLint::Line;

BEGIN {
	import PkgLint::Util qw(
		false true
		assert
	);
}

use enum qw(FNAME LINES TEXT PHYSLINES CHANGED BEFORE AFTER EXTRA);

sub new($$$$) {
	my ($class, $fname, $lines, $text, $physlines) = @_;
	my ($self) = ([$fname, $lines, $text, $physlines, false, [], [], {}]);
	bless($self, $class);
	return $self;
}

sub fname($)		{ return shift()->[FNAME]; }
sub lines($)		{ return shift()->[LINES]; }
sub text($)		{ return shift()->[TEXT]; }
# Note: physlines is _not_ a simple getter method.
sub is_changed($)	{ return shift()->[CHANGED]; }

# querying, getting and setting the extra values.
sub has($$) {
	my ($self, $name) = @_;
	return exists($self->[EXTRA]->{$name});
}
sub get($$) {
	my ($self, $name) = @_;
	assert(exists($self->[EXTRA]->{$name}), "Field ${name} does not exist.");
	return $self->[EXTRA]->{$name};
}
sub set($$$) {
	my ($self, $name, $value) = @_;
	assert(!exists($self->[EXTRA]->{$name}), "Field ${name} already exists.");

	# Make sure that the line does not become a cyclic data structure.
	my $type = ref($value);
	if ($type eq "") {
		# ok
	} elsif ($type eq "ARRAY") {
		foreach my $element (@{$value}) {
			my $element_type = ref($element);
			assert($element_type eq "" || $element_type eq "PkgLint::SimpleMatch",
				"Invalid array data type: name=${name}, type=${element_type}.");
		}
	} else {
		assert(false, "Invalid data: name=${name}, value=${value}.");
	}

	$self->[EXTRA]->{$name} = $value;
}

sub physlines($) {
	my ($self) = @_;
	return [@{$self->[BEFORE]}, @{$self->[PHYSLINES]}, @{$self->[AFTER]}];
}

# Only for PkgLint::String support
sub substring($$$$) {
	my ($self, $line, $start, $end) = @_;

	return substr($self->[PHYSLINES]->[$line]->[1], $start, $end);
}

sub show_source($$) {
	my ($self, $out) = @_;

	if (PkgLint::Logging::get_show_source_flag()) {
		foreach my $line (@{$self->physlines}) {
			print $out ("> " . $line->[1]);
		}
	}
}

sub log_fatal($$) {
	my ($self, $text) = @_;

	$self->show_source(*STDERR);
	PkgLint::Logging::log_fatal($self->fname, $self->[LINES], $text);
}
sub log_error($$) {
	my ($self, $text) = @_;

	$self->show_source(*STDOUT);
	PkgLint::Logging::log_error($self->fname, $self->[LINES], $text);
}
sub log_warning($$) {
	my ($self, $text) = @_;

	$self->show_source(*STDOUT);
	PkgLint::Logging::log_warning($self->fname, $self->[LINES], $text);
}
sub log_note($$) {
	my ($self, $text) = @_;

	$self->show_source(*STDOUT);
	PkgLint::Logging::log_note($self->fname, $self->[LINES], $text);
}
sub log_debug($$) {
	my ($self, $text) = @_;

	$self->show_source(*STDOUT);
	PkgLint::Logging::log_debug($self->fname, $self->[LINES], $text);
}
sub explain_error($@) {
	my ($self, @texts) = @_;

	PkgLint::Logging::explain_error($self->fname, $self->[LINES], @texts);
}
sub explain_warning($@) {
	my ($self, @texts) = @_;

	PkgLint::Logging::explain_warning($self->fname, $self->[LINES], @texts);
}
sub explain_note($@) {
	my ($self, @texts) = @_;

	PkgLint::Logging::explain_note($self->fname, $self->[LINES], @texts);
}
sub explain_info($@) {
	my ($self, @texts) = @_;

	PkgLint::Logging::explain_info($self->fname, $self->[LINES], @texts);
}

sub to_string($) {
	my ($self) = @_;

	return $self->fname . ":" . $self->[LINES] . ": " . $self->[TEXT];
}

sub prepend_before($$) {
	my ($self, $text) = @_;

	unshift(@{$self->[BEFORE]}, [0, "$text\n"]);
	$self->[CHANGED] = true;
}
sub append_before($$) {
	my ($self, $text) = @_;

	push(@{$self->[BEFORE]}, [0, "$text\n"]);
	$self->[CHANGED] = true;
}
sub prepend_after($$) {
	my ($self, $text) = @_;

	unshift(@{$self->[AFTER]}, [0, "$text\n"]);
	$self->[CHANGED] = true;
}
sub append_after($$) {
	my ($self, $text) = @_;

	push(@{$self->[AFTER]}, [0, "$text\n"]);
	$self->[CHANGED] = true;
}
sub delete($) {
	my ($self) = @_;

	$self->[PHYSLINES] = [];
	$self->[CHANGED] = true;
}
sub replace($$$) {
	my ($self, $from, $to) = @_;
	my $phys = $self->[PHYSLINES];

	foreach my $i (0..$#{$phys}) {
		if ($phys->[$i]->[0] != 0 && $phys->[$i]->[1] =~ s/\Q$from\E/$to/g) {
			$self->[CHANGED] = true;
		}
	}
}
sub replace_regex($$$) {
	my ($self, $from_re, $to) = @_;
	my $phys = $self->[PHYSLINES];

	foreach my $i (0..$#{$phys}) {
		if ($phys->[$i]->[0] != 0 && $phys->[$i]->[1] =~ s/$from_re/$to/) {
			$self->[CHANGED] = true;
		}
	}
}
sub set_text($$) {
	my ($self, $text) = @_;
	$self->[PHYSLINES] = [[0, "$text\n"]];
	$self->[CHANGED] = true;
}

#== End of PkgLint::Line ==================================================

1;
