#==========================================================================
# A SimpleMatch is the result of applying a regular expression to a Perl
# scalar value. It can return the range and the text of the captured
# groups.
#==========================================================================
package PkgLint::SimpleMatch;

use enum qw(STRING STARTS ENDS N);

sub new($$) {
	my ($class, $string, $starts, $ends) = @_;
	my ($self) = ([$string, [@{$starts}], [@{$ends}], $#{$ends}]);
	bless($self, $class);
	return $self;
}

sub string($)		{ return shift()->[STRING]; }
sub n($)		{ return shift()->[N]; }

sub has($$) {
	my ($self, $n) = @_;

	return 0 <= $n && $n <= $self->n
	    && defined($self->[STARTS]->[$n])
	    && defined($self->[ENDS]->[$n]);
}

sub text($$) {
	my ($self, $n) = @_;

	my $start = $self->[STARTS]->[$n];
	my $end = $self->[ENDS]->[$n];
	return substr($self->string, $start, $end - $start);
}

sub range($$) {
	my ($self, $n) = @_;

	return ($self->[STARTS]->[$n], $self->[ENDS]->[$n]);
}

1;
