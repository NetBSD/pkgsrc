package PkgLint::Change;
#==========================================================================
# A change entry from doc/CHANGES-*
#==========================================================================

sub new($$$$$$) {
	my ($class, $line, $action, $pkgpath, $version, $author, $date) = @_;
	my $self = [ $line, $action, $pkgpath, $version, $author, $date ];
	bless($self, $class);
	return $self;
}
sub line($)			{ return shift()->[0]; }
sub action($)			{ return shift()->[1]; }
sub pkgpath($)			{ return shift()->[2]; }
sub version($)			{ return shift()->[3]; }
sub author($)			{ return shift()->[4]; }
sub date($)			{ return shift()->[5]; }
#== End of PkgLint::Change ================================================

1;
