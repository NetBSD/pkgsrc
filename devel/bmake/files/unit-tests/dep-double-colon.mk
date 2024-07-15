# $NetBSD: dep-double-colon.mk,v 1.1 2024/07/15 09:10:13 jperkin Exp $
#
# Tests for the '::' operator in dependency declarations, which allows
# several dependency groups for a single node, each having its own attributes
# and dependencies.  In the code, the additional dependency groups are called
# cohorts.

all::
	@echo 'command 1a'
	@echo 'command 1b'

all::
	@echo 'command 2a'
	@echo 'command 2b'

# When there are multiple command groups for a '::' target, each of these
# groups is added separately to the .ALLTARGETS variable.
#
# XXX: What is this good for?
# XXX: Where does the leading space come from?
.if ${.ALLTARGETS} != " all all"
.  error
.endif
