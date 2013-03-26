package PkgLint::CVS_Entry;
#==========================================================================
# A CVS_Entry represents one line from a CVS/Entries file.
#==========================================================================

use enum qw(FNAME REVISION MTIME TAG);

sub new($$$$$) {
	my ($class, $fname, $revision, $date, $tag) = @_;
	my $self = [ $fname, $revision, $date, $tag ];
	bless($self, $class);
	return $self;
}
sub fname($)			{ return shift()->[FNAME]; }
sub revision($)			{ return shift()->[REVISION]; }
sub mtime($)			{ return shift()->[MTIME]; }
sub tag($)			{ return shift()->[TAG]; }
#== End of PkgLint::CVS_Entry =============================================

1;
