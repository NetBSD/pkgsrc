# $NetBSD: happy.mk,v 1.1 2021/05/01 16:14:19 pho Exp $
#
# Usage: USE_TOOLS+= happy
#

HAPPY_REQD?=	0
TOOLS_CREATE+=	happy

.if !empty(USE_TOOLS:Mhappy)
TOOLS_DEPENDS.happy?=	happy>=${HAPPY_REQD}:../../devel/happy
TOOLS_PATH.happy=	${PREFIX}/bin/happy
.else
# We can't use TOOLS_FAIL because Cabal tries to invoke all of
# relevant tools regardless of whether they are actually required.
TOOLS_SCRIPT.happy=	\
	${FAIL_MSG} "To use this tool, add USE_TOOLS+=happy to the package Makefile."
.endif
