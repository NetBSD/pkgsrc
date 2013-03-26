package PkgLint::VarUseContext;
#==========================================================================
# This class represents the various contexts in which make(1) variables can
# appear in pkgsrc. Further details can be found in the chapter ``The
# pkglint type system'' of the pkglint book.
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
		VUC_TIME_UNKNOWN VUC_TIME_LOAD VUC_TIME_RUN
		VUC_TYPE_UNKNOWN
		VUC_SHELLWORD_UNKNOWN VUC_SHELLWORD_PLAIN VUC_SHELLWORD_DQUOT
		  VUC_SHELLWORD_SQUOT VUC_SHELLWORD_BACKT VUC_SHELLWORD_FOR
		VUC_EXTENT_UNKNOWN VUC_EXTENT_FULL VUC_EXTENT_WORD
		  VUC_EXTENT_WORD_PART
	);
}

use enum qw(TIME TYPE SHELLWORD EXTENT);
use enum qw(:VUC_TIME_ UNKNOWN LOAD RUN);
use constant VUC_TYPE_UNKNOWN => undef;
use enum qw(:VUC_SHELLWORD_ UNKNOWN PLAIN DQUOT SQUOT BACKT FOR);
use enum qw(:VUC_EXTENT_ UNKNOWN FULL WORD WORD_PART);

my $pool = {};

sub new($$$$$) {
	my ($class, $time, $type, $shellword, $extent) = @_;
	my ($self) = ([$time, $type, $shellword, $extent]);
	bless($self, $class);
	return $self;
}
sub new_from_pool($$$$$) {
	my ($class, $time, $type, $shellword, $extent) = @_;
	my $key = "${time}-${type}-${shellword}-${extent}";

	if (!exists($pool->{$key})) {
		$pool->{$key} = $class->new($time, $type, $shellword, $extent);
	}
	return $pool->{$key};
}

sub time($)		{ return shift()->[TIME]; }
sub type($)		{ return shift()->[TYPE]; }
sub shellword($)	{ return shift()->[SHELLWORD]; }
sub extent($)		{ return shift()->[EXTENT]; }

sub to_string($) {
	my ($self) = @_;

	return sprintf("(%s %s %s %s)",
	    ["unknown-time", "load-time", "run-time"]->[$self->time],
	    (defined($self->type) ? $self->type->to_string() : "no-type"),
	    ["none", "plain", "squot", "dquot", "backt", "for"]->[$self->shellword],
	    ["unknown", "full", "word", "word-part"]->[$self->extent]);
}

#== End of PkgLint::VarUseContext =========================================

1;
