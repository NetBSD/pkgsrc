# $NetBSD: options.mk,v 1.2 2023/06/06 12:41:34 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libpgf
PKG_SUPPORTED_OPTIONS=	doc

PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		doxygen>=1.8.7:../../devel/doxygen
PLIST.doc=		yes
CONFIGURE_ARGS+=	--enable-doc
.endif
