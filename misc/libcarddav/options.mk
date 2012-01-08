# $NetBSD: options.mk,v 1.1.1.1 2012/01/08 15:18:40 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libcarddav
PKG_SUPPORTED_OPTIONS=	doxygen
PKG_SUGGESTED_OPTIONS=	doxygen

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doxygen

.if !empty(PKG_OPTIONS:Mdoxygen)
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
BUILD_DEPENDS+=		tex-ec-[0-9]*:../../fonts/tex-ec
CONFIGURE_ARGS+=	--enable-doc
PLIST.doxygen=		yes
.else
CONFIGURE_ARGS+=	--disable-doxygen-doc
.endif
