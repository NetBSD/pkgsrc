# $NetBSD: bug2.mk,v 1.2 2005/08/01 01:02:05 rillig Exp $
#
# This file demonstrates a subtle inconsistency that only occurs when an
# undefined variable is used in another, which is then quoted and copied
# by using the := assignment operator.

.undef UNDEFINED

# this variable references the undefined variable
UNDEF_REF=	${UNDEFINED}

# and the current value is assigned to another variable
UNDEF_VALUE:=	${UNDEF_REF:Q}

all:
	@echo UNDEFINED=${UNDEFINED:Q}""
	@echo UNDEF_REF=${UNDEF_REF:Q}""
	@echo UNDEF_VALUE=${UNDEF_VALUE:Q}""
