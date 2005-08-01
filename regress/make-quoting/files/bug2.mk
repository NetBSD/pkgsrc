# $NetBSD: bug2.mk,v 1.1 2005/08/01 00:40:30 rillig Exp $
#
# This file demonstrates a subtle inconsistency that only occurs when an
# undefined variable is used in another, which is then quoted and copied
# by using the := assignment operator.

.undef UNDEFINED

# this variable references the undefined variable
UNDEF_REF=	${UNDEFINED}

# here the reference is quoted
VARS+=		${UNDEF_REF:Q}

# and the current value is assigned to another variable
VARS_VALUE:=	${VARS}

all:
	@echo UNDEFINED=${UNDEFINED:Q}""
	@echo UNDEF_REF=${UNDEF_REF:Q}""
	@echo VARS=${VARS:Q}""
	@echo VARS_VALUE=${VARS_VALUE:Q}""
