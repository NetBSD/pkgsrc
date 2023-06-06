# $NetBSD: options.mk,v 1.2 2023/06/06 12:40:17 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opus
PKG_SUPPORTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-doc
.endif
