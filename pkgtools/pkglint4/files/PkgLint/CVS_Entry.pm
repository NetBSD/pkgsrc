# $NetBSD: CVS_Entry.pm,v 1.1 2015/11/25 16:42:21 rillig Exp $
#
# One line from a CVS/Entries file.
#
package PkgLint::CVS_Entry;

use strict;
use warnings;

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
