# $NetBSD: dirs.mk,v 1.1 2022/10/06 02:18:16 markd Exp $

.include "../../mk/bsd.prefs.mk"

RT_LOCAL_DIR?=		${VARBASE}/rt5
BUILD_DEFS+=		RT_LOCAL_DIR

RT_EXAMPLE_DIR=	${PREFIX}/share/examples/rt5
RT_SHARE_DIR=	${PREFIX}/share/rt5
RT_VAR_DIR=	${VARBASE}/spool/rt5
