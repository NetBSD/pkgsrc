# $NetBSD: depsrc-optional.mk,v 1.2 2024/09/17 11:52:30 jperkin Exp $
#
# Tests for the special source .OPTIONAL in dependency declarations,
# which ignores the target if make cannot find out how to create it.
#
# TODO: Describe practical use cases for this feature.

all: important
	: ${.TARGET} is made.

important: optional optional-cohort
	: ${.TARGET} is made.

optional: .OPTIONAL
	: An optional leaf node is not executed.

# See IsOODateRegular.
optional-cohort:: .OPTIONAL
	: A leaf node using '::' is considered out-of-date.

.MAKEFLAGS: -dm
