# $NetBSD: options.mk,v 1.3 2024/04/26 15:43:05 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libopus
PKG_SUPPORTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-doc
.endif
