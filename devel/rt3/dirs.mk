# $NetBSD: dirs.mk,v 1.3 2008/08/23 23:58:29 tonnerre Exp $

.include "../../mk/bsd.prefs.mk"

RT_LOCAL_DIR?=		${VARBASE}/rt3
BUILD_DEFS+=		RT_LOCAL_DIR

RT_DOC_DIR=	${PREFIX}/share/doc/rt3
RT_EXAMPLE_DIR= ${PREFIX}/share/examples/rt3
RT_LIB_DIR=	${PREFIX}/lib/rt3
RT_SHARE_DIR=	${PREFIX}/share/rt3
RT_VAR_DIR=	${VARBASE}/spool/rt3

RT_HTML_DIR=	${RT_SHARE_DIR}/html
RT_I18N_DIR=	${RT_LIB_DIR}/RT/I18N
