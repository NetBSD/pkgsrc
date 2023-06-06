# $NetBSD: options.mk,v 1.2 2023/06/06 12:40:40 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libnet
PKG_SUPPORTED_OPTIONS=	doxygen

PLIST_VARS+=		doxygen

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoxygen)
TOOL_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
PLIST.doxygen=		yes
.else
CONFIGURE_ARGS+=	--disable-doxygen-doc
.endif
