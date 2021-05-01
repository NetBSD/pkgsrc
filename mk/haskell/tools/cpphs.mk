# $NetBSD: cpphs.mk,v 1.1 2021/05/01 16:14:19 pho Exp $
#
# Usage: USE_TOOLS+= cpphs
#

CPPHS_REQD?=	0
TOOLS_CREATE+=		cpphs

.if !empty(USE_TOOLS:Mcpphs)
TOOLS_DEPENDS.cpphs?=	hs-cpphs>=${CPPHS_REQD}:../../devel/hs-cpphs
TOOLS_PATH.cpphs=	${PREFIX}/bin/cpphs
.else
# We can't use TOOLS_FAIL because Cabal tries to invoke all of
# relevant tools regardless of whether they are actually required.
TOOLS_SCRIPT.cpphs=	\
	${FAIL_MSG} "To use this tool, add USE_TOOLS+=cpphs to the package Makefile."
.endif
