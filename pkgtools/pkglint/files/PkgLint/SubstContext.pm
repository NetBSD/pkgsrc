package PkgLint::SubstContext;
#==========================================================================
# This class records the state of a block of variable assignments that make
# up a SUBST class. As these variable assignments are not easy to get right
# unless you do it every day, and the possibility of typos is high, pkglint
# provides additional checks for them.
#==========================================================================

BEGIN {
	import PkgLint::Util qw(
		false true
	);
	import PkgLint::Logging qw(
		log_warning
	);
}

use enum qw(:SUBST_ ID CLASS STAGE MESSAGE FILES SED VARS FILTER_CMD);

sub new($) {
	my ($class) = @_;
	my ($self) = ([undef, undef, undef, undef, [], [], [], undef]);
	bless($self, $class);
	return $self;
}

sub subst_class($)		{ return shift()->[SUBST_CLASS]; }
sub subst_stage($)		{ return shift()->[SUBST_STAGE]; }
sub subst_message($)		{ return shift()->[SUBST_MESSAGE]; }
sub subst_files($)		{ return shift()->[SUBST_FILES]; }
sub subst_sed($)		{ return shift()->[SUBST_SED]; }
sub subst_vars($)		{ return shift()->[SUBST_VARS]; }
sub subst_filter_cmd($)		{ return shift()->[SUBST_FILTER_CMD]; }
sub subst_id($)			{ return shift()->[SUBST_ID]; }

sub init($) {
	my ($self) = @_;

	$self->[SUBST_ID] = undef;
	$self->[SUBST_CLASS] = undef;
	$self->[SUBST_STAGE] = undef;
	$self->[SUBST_MESSAGE] = undef;
	$self->[SUBST_FILES] = [];
	$self->[SUBST_SED] = [];
	$self->[SUBST_VARS] = [];
	$self->[SUBST_FILTER_CMD] = undef;
}

sub check_end($$) {
	my ($self, $line) = @_;

	return unless defined($self->subst_id);

	if (!defined($self->subst_class)) {
		$main::opt_warn_extra and $line->log_warning("Incomplete SUBST block: SUBST_CLASSES missing.");
	}
	if (!defined($self->subst_stage)) {
		$main::opt_warn_extra and $line->log_warning("Incomplete SUBST block: SUBST_STAGE missing.");
	}
	if (@{$self->subst_files} == 0) {
		$main::opt_warn_extra and $line->log_warning("Incomplete SUBST block: SUBST_FILES missing.");
	}
	if (@{$self->subst_sed} == 0 && @{$self->subst_vars} == 0 && !defined($self->subst_filter_cmd)) {
		$main::opt_warn_extra and $line->log_warning("Incomplete SUBST block: SUBST_SED or SUBST_VARS missing.");
	}
	$self->init();
}

sub is_complete($) {
	my ($self) = @_;

	return false unless defined($self->subst_id);
	return false unless defined($self->subst_class);
	return false unless defined($self->subst_files);
	return false if @{$self->subst_sed} == 0 && @{$self->subst_vars} == 0;
	return true;
}

sub check_varassign($$$$$) {
	my ($self, $line, $varname, $op, $value) = @_;
	my ($varbase, $varparam, $id);

	if ($varname eq "SUBST_CLASSES") {

		if ($value =~ m"^(\S+)\s") {
			$main::opt_warn_extra and $line->log_warning("Please add only one class at a time to SUBST_CLASSES.");
			$self->[SUBST_CLASS] = $1;
			$self->[SUBST_ID] = $1;

		} else {
			if (defined($self->subst_class)) {
				$main::opt_warn_extra and $line->log_warning("SUBST_CLASSES should only appear once in a SUBST block.");
			}
			$self->[SUBST_CLASS] = $value;
			$self->[SUBST_ID] = $value;
		}
		return;
	}

	$id = $self->subst_id;

	if ($varname =~ m"^(SUBST_(?:STAGE|MESSAGE|FILES|SED|VARS|FILTER_CMD))\.([\-\w_]+)$") {
		($varbase, $varparam) = ($1, $2);

		if (!defined($id)) {
			$main::opt_warn_extra and $line->log_note("SUBST_CLASSES should precede the definition of ${varbase}.${varparam}.");

			$id = $self->[SUBST_ID] = $varparam;
		}
	} else {
		if (defined($id)) {
			$main::opt_warn_extra and $line->log_warning("Foreign variable in SUBST block.");
		}
		return;
	}

	if ($varparam ne $id) {

		# XXX: This code sometimes produces weird warnings. See
		# meta-pkgs/xorg/Makefile.common 1.41 for an example.
		if ($self->is_complete()) {
			$self->check_end($line);

			# The following assignment prevents an additional warning,
			# but from a technically viewpoint, it is incorrect.
			$self->[SUBST_CLASS] = $varparam;
			$self->[SUBST_ID] = $varparam;
			$id = $varparam;
		} else {
			$main::opt_warn_extra and $line->log_warning("Variable parameter \"${varparam}\" does not match SUBST class \"${id}\".");
		}
	}

	if ($varbase eq "SUBST_STAGE") {
		if (defined($self->subst_stage)) {
			$main::opt_warn_extra and $line->log_warning("Duplicate definition of SUBST_STAGE.${id}.");
		} else {
			$self->[SUBST_STAGE] = $value;
		}

	} elsif ($varbase eq "SUBST_MESSAGE") {
		if (defined($self->subst_message)) {
			$main::opt_warn_extra and $line->log_warning("Duplicate definition of SUBST_MESSAGE.${id}.");
		} else {
			$self->[SUBST_MESSAGE] = $value;
		}

	} elsif ($varbase eq "SUBST_FILES") {
		if (@{$self->subst_files} > 0) {
			if ($op ne "+=") {
				$main::opt_warn_extra and $line->log_warning("All but the first SUBST_FILES line should use the \"+=\" operator.");
			}
		}
		push(@{$self->subst_files}, $value);

	} elsif ($varbase eq "SUBST_SED") {
		if (@{$self->subst_sed} > 0) {
			if ($op ne "+=") {
				$main::opt_warn_extra and $line->log_warning("All but the first SUBST_SED line should use the \"+=\" operator.");
			}
		}
		push(@{$self->subst_sed}, $value);

	} elsif ($varbase eq "SUBST_FILTER_CMD") {
		if (defined($self->subst_filter_cmd)) {
			$main::opt_warn_extra and $line->log_warning("Duplicate definition of SUBST_FILTER_CMD.${id}.");
		} else {
			$self->[SUBST_FILTER_CMD] = $value;
		}

	} elsif ($varbase eq "SUBST_VARS") {
		if (@{$self->subst_vars} > 0) {
			if ($op ne "+=") {
				$main::opt_warn_extra and $line->log_warning("All but the first SUBST_VARS line should use the \"+=\" operator.");
			}
		}
		push(@{$self->subst_vars}, $value);

	} else {
		$main::opt_warn_extra and $line->log_warning("Foreign variable in SUBST block.");
	}
}

sub to_string($) {
	my ($self) = @_;

	return sprintf("SubstContext(%s %s %s %s %s %s)",
	    (defined($self->subst_class) ? $self->subst_class : "(undef)"),
	    (defined($self->subst_stage) ? $self->subst_stage : "(undef)"),
	    (defined($self->subst_message) ? $self->subst_message : "(undef)"),
	    scalar(@{$self->subst_files}),
	    scalar(@{$self->subst_sed}),
	    (defined($self->subst_id) ? $self->subst_id : "(undef)"));
}
#== End of PkgLint::SubstContext ==========================================

1;
