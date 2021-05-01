# $NetBSD: alex.mk,v 1.1 2021/05/01 16:14:19 pho Exp $
#
# Usage: USE_TOOLS+= alex
#

ALEX_REQD?=	0
TOOLS_CREATE+=	alex

.if !empty(USE_TOOLS:Malex)
TOOLS_DEPENDS.alex?=	alex>=${ALEX_REQD}:../../devel/alex
TOOLS_PATH.alex=	${PREFIX}/bin/alex
.else
# We can't use TOOLS_FAIL because Cabal tries to invoke all of
# relevant tools regardless of whether they are actually required.
TOOLS_SCRIPT.alex=	\
	${FAIL_MSG} "To use this tool, add USE_TOOLS+=alex to the package Makefile."
.endif
