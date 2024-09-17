# $NetBSD: varname-dot-make-level.mk,v 1.2 2024/09/17 11:52:35 jperkin Exp $
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
