#! /bin/sh
#
# This file demonstrates which patterns are detected by the check for
# the == operator.

test a = b	# good
test a == b	# bad

[ a = b ]	# good
[ a == b ]	# bad

# The check does not look at the closing bracket as that would generate
# too many special cases.
[ a == b -a c == d ]

# This case is not found since the == operator is not at the beginning
# of the condition. This constellation doesn't occur in practice though.
[ a = b -a c == d ]
