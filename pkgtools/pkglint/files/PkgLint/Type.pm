package PkgLint::Type;
#==========================================================================
# A Type in pkglint is a combination of a data type and a permission
# specification. Further details can be found in the chapter ``The pkglint
# type system'' of the pkglint book.
#==========================================================================

BEGIN {
	import PkgLint::Util qw(
		false true
	);
	import PkgLint::Logging qw(
		log_warning NO_LINES
	);
	use Exporter;
	use vars qw(@ISA @EXPORT_OK);
	@ISA = qw(Exporter);
	@EXPORT_OK = qw(
		LK_NONE LK_INTERNAL LK_EXTERNAL
		GUESSED NOT_GUESSED
	);
}

use enum qw(KIND_OF_LIST BASIC_TYPE ACLS IS_GUESSED);
use enum qw(:LK_ NONE INTERNAL EXTERNAL);
use enum qw(:ACLE_ SUBJECT_RE PERMS);
use enum qw(NOT_GUESSED GUESSED);

sub new($$$) {
	my ($class, $kind_of_list, $basic_type, $acls, $guessed) = @_;
	my ($self) = ([$kind_of_list, $basic_type, $acls, $guessed]);
	bless($self, $class);
	return $self;
}

sub kind_of_list($)	{ return shift()->[KIND_OF_LIST]; }
sub basic_type($)	{ return shift()->[BASIC_TYPE]; }
# no getter method for acls
sub is_guessed($)	{ return shift()->[IS_GUESSED]; }

sub perms($$) {
	my ($self, $fname) = @_;
	my ($perms);

	foreach my $acl_entry (@{$self->[ACLS]}) {
		if ($fname =~ $acl_entry->[ACLE_SUBJECT_RE]) {
			return $acl_entry->[ACLE_PERMS];
		}
	}
	return undef;
}

# Returns the union of all possible permissions. This can be used to
# check whether a variable may be defined or used at all, or if it is
# read-only.
sub perms_union($) {
	my ($self) = @_;
	my ($perms);

	$perms = "";
	foreach my $acl_entry(@{$self->[ACLS]}) {
		$perms .= $acl_entry->[ACLE_PERMS];
	}
	return $perms;
}

# Returns whether the type is considered an external list. All external
# lists are, of course, as well as some other data types that are not
# defined as lists to make the implementation of checkline_mk_vartype
# easier.
sub is_practically_a_list($) {
	my ($self) = @_;

	return ($self->kind_of_list == LK_EXTERNAL) ? true
	    : ($self->kind_of_list == LK_INTERNAL) ? false
	    : ($self->basic_type eq "BuildlinkPackages") ? true
	    : ($self->basic_type eq "SedCommands") ? true
	    : ($self->basic_type eq "ShellCommand") ? true
	    : false;
}

# Returns whether variables of this type may be extended using the "+="
# operator.
sub may_use_plus_eq($) {
	my ($self) = @_;

	return ($self->kind_of_list != LK_NONE) ? true
	    : ($self->basic_type eq "AwkCommand") ? true
	    : ($self->basic_type eq "BuildlinkPackages") ? true
	    : ($self->basic_type eq "SedCommands") ? true
	    : false;
}

sub to_string($) {
	my ($self) = @_;

	return (["", "InternalList of ", "List of "]->[$self->kind_of_list]) . $self->basic_type;
}

#== End of PkgLint::Type ==================================================

1;
