# $NetBSD: varname-dot-make-level.mk,v 1.1 2024/07/15 09:10:32 jperkin Exp $
#
# Tests for the special .MAKE.LEVEL variable, which informs about the
# recursion level.  It is related to the environment variable MAKELEVEL,
# even though they don't have the same value.

level_1: .PHONY
	@printf 'level 1: variable %s, env %s\n' ${.MAKE.LEVEL} "$$${.MAKE.LEVEL.ENV}"
	@${MAKE} -f ${MAKEFILE} level_2

level_2: .PHONY
	@printf 'level 2: variable %s, env %s\n' ${.MAKE.LEVEL} "$$${.MAKE.LEVEL.ENV}"
	@${MAKE} -f ${MAKEFILE} level_3

level_3: .PHONY
	@printf 'level 3: variable %s, env %s\n' ${.MAKE.LEVEL} "$$${.MAKE.LEVEL.ENV}"

# The .unexport-env directive clears the environment, except for the
# MAKE_LEVEL variable.
.if make(level_2)
.unexport-env
.endif
