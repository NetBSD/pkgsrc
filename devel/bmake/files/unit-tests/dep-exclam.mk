# $NetBSD: dep-exclam.mk,v 1.2 2024/09/17 11:52:30 jperkin Exp $
#
# Tests for the ! operator in dependency declarations, which always re-creates
# the target, whether or not it is out of date.
#
# TODO: Is this related to OP_PHONY?
# TODO: Is this related to OP_EXEC?
# TODO: Is this related to OP_MAKE?

# TODO: Implementation

all:
	@:;
