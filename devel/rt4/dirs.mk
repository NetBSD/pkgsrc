# $NetBSD: dirs.mk,v 1.1 2014/06/17 11:10:40 markd Exp $

.include "../../mk/bsd.prefs.mk"

RT_LOCAL_DIR?=		${VARBASE}/rt4
BUILD_DEFS+=		RT_LOCAL_DIR

RT_EXAMPLE_DIR= ${PREFIX}/share/examples/rt4
RT_SHARE_DIR=	${PREFIX}/share/rt4
RT_VAR_DIR=	${VARBASE}/spool/rt4
