# $NetBSD: options.mk,v 1.1 2025/11/02 18:44:06 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fish4
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS+=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc

.if !empty(PKG_OPTIONS:Mdoc)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_DOCS=ON
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx>0:../../textproc/py-sphinx
PLIST.doc=		yes
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_DOCS=OFF
.endif
