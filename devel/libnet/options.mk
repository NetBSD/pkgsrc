# $NetBSD: options.mk,v 1.1 2021/07/21 22:35:25 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libnet
PKG_SUPPORTED_OPTIONS=	doxygen

PLIST_VARS+=		doxygen

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoxygen)
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
PLIST.doxygen=		yes
.else
CONFIGURE_ARGS+=	--disable-doxygen-doc
.endif
