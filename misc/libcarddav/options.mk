# $NetBSD: options.mk,v 1.3 2012/07/11 14:47:23 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libcarddav
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=	doc
PKG_OPTIONS_LEGACY_OPTS+=	doxygen:doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=		doxygen>=1.8.1.1:../../devel/doxygen
BUILD_DEPENDS+=		tex-ec-[0-9]*:../../fonts/tex-ec
BUILD_DEPENDS+=		tex-tocloft-[0-9]*:../../print/tex-tocloft
BUILD_DEPENDS+=		tex-xtab-[0-9]*:../../print/tex-xtab
BUILD_DEPENDS+=		tex-multirow-[0-9]*:../../print/tex-multirow
CONFIGURE_ARGS+=	--enable-doc
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-doxygen-doc
.endif
