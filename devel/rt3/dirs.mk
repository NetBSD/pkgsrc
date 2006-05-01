# $NetBSD: dirs.mk,v 1.1 2006/05/01 09:38:08 cube Exp $

.include "../../mk/bsd.prefs.mk"

RT_LOCAL_DIR?=		${VARBASE}/rt3
BUILD_DEFS+=		RT_LOCAL_DIR

RT_DOC_DIR=	${LOCALBASE}/share/doc/rt3
RT_EXAMPLE_DIR= ${LOCALBASE}/share/examples/rt3
RT_LIB_DIR=	${LOCALBASE}/lib/rt3
RT_SHARE_DIR=	${LOCALBASE}/share/rt3
RT_VAR_DIR=	${VARBASE}/spool/rt3

RT_HTML_DIR=	${RT_SHARE_DIR}/html
RT_I18N_DIR=	${RT_LIB_DIR}/I18N
