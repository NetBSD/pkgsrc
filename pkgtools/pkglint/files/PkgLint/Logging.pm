package PkgLint::Logging;
#==========================================================================
# This package provides subroutines for printing messages to the user in a
# common format. The subroutines all have the parameters C<$fname>,
# C<$lineno> and C<$message>. In case there's no appropriate filename for
# the message, NO_FILE may be passed, likewise for C<$lineno> and
# NO_LINES. Before printing, the filename is normalized, that is,
# "/foo/bar/../../" components are removed, as well as "." components.
# At the end of the program, the subroutine print_summary_and_exit should
# be called.
#
# Examples:
#   log_error(NO_FILE, NO_LINES, "Invalid command line.");
#   log_warning($fname, NO_LINES, "Not found.");
#   log_debug($fname, $lineno, sprintf("invalid character (0x%02x).", $c));
#==========================================================================

use strict;
use warnings;
BEGIN {
	use Exporter;
	use vars qw(@ISA @EXPORT_OK);
	@ISA = qw(Exporter);
	@EXPORT_OK = qw(
		NO_FILE NO_LINE_NUMBER NO_LINES
		log_fatal log_error log_warning log_note log_debug
		explain_error explain_warning explain_info
		print_summary_and_exit
		set_explain set_gcc_output_format
		get_show_source_flag set_show_source_flag
	);
	import PkgLint::Util qw(
		false true
		normalize_pathname
	);
}

use constant NO_FILE		=> undef;
use constant NO_LINE_NUMBER	=> undef;
use constant NO_LINES		=> undef;

use enum qw(:LL_ FATAL ERROR WARNING NOTE DEBUG);

use constant traditional_type	=> ["FATAL", "ERROR", "WARN", "NOTE", "DEBUG"];
use constant gcc_type		=> ["fatal", "error", "warning", "note", "debug"];

my $errors		= 0;
my $warnings		= 0;
my $gcc_output_format	= false;
my $explain_flag	= false;
my $show_source_flag	= false;

sub strxvis($) {
	my ($s) = @_;

	$s =~ s/([^\x09\x20-\x7e])/"\\x" . unpack("H*", $1)/eg;
	return $s;
}

sub log_message { # no prototype due to Perl weirdness
	my ($level, $fname, $lineno, $message) = @_;
	my ($text, $sep);

	if (defined($fname)) {
		$fname = normalize_pathname($fname);
	}

	$text = "";
	$sep = "";
	if (!$gcc_output_format) {
		$text .= "${sep}" . traditional_type->[$level] . ":";
		$sep = " ";
	}
	if (defined($fname)) {
		$text .= defined($lineno)
		    ? "${sep}${fname}:${lineno}"
		    : "${sep}${fname}";
		$sep = ": ";
	}
	if ($gcc_output_format) {
		$text .= "${sep}" . gcc_type->[$level] . ":";
		$sep = " ";
	}
	if (defined($message)) {
		$text .= $sep . strxvis($message);
		$sep = "";
	}

	if ($level == LL_FATAL) {
		print STDERR ("${text}\n");
	} else {
		print STDOUT ("${text}\n");
	}
}

sub log_fatal($$$)		{ log_message(LL_FATAL, @_); exit(1); }
sub log_error($$$)		{ log_message(LL_ERROR, @_); $errors++; }
sub log_warning($$$)		{ log_message(LL_WARNING, @_); $warnings++; }
sub log_note($$$)		{ log_message(LL_NOTE, @_); }
sub log_debug($$$)		{ log_message(LL_DEBUG, @_); }

sub explain { # no prototype due to Perl weirdness
	my ($loglevel, $fname, $lines, @texts) = @_;
	my $out = ($loglevel == LL_FATAL) ? *STDERR : *STDOUT;

	if ($explain_flag) {
		foreach my $text ("", @texts, "") {
			print $out ("\t${text}\n");
		}
	}
}
sub explain_error($$@)		{ explain(LL_ERROR, @_); }
sub explain_warning($$@)	{ explain(LL_WARNING, @_); }
sub explain_note($$@)		{ explain(LL_NOTE, @_); }

sub print_summary_and_exit($) {
	my ($quiet) = @_;

	if (!$quiet) {
		if ($errors != 0 || $warnings != 0) {
			print("$errors errors and $warnings warnings found." . ($explain_flag ? "" : " (Use -e for more details.)") . "\n");
		} else {
			print "looks fine.\n";
		}
	}
	exit($errors != 0);
}

sub set_explain()		{ $explain_flag = true; }
sub set_gcc_output_format()	{ $gcc_output_format = true; }
sub get_show_source_flag()	{ return $show_source_flag; }
sub set_show_source_flag()	{ $show_source_flag = true; }

#== End of PkgLint::Logging ===============================================

1;
