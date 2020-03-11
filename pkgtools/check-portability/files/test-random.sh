#! /bin/sh
#
# This file demonstrates which patterns are detected by the check for
# random numbers without other sources of randomness.

# Having a single low-entropy random source is bad.
$RANDOM

# These two are ok.
$RANDOM-$$
$$-$RANDOM

# This is not the style used in GNU configure scripts, thus no warning
# is necessary. This doesn't occur in practice.
${RANDOM}
