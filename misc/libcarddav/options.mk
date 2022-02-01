# $NetBSD: options.mk,v 1.10 2022/02/01 11:58:35 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libcarddav
PKG_SUPPORTED_OPTIONS=		doc
PKG_SUGGESTED_OPTIONS=		doc
PKG_OPTIONS_LEGACY_OPTS+=	doxygen:doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc

.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=		doxygen>=1.8.1.1:../../devel/doxygen
BUILD_DEPENDS+=		tex-alphalph-[0-9]*:../../print/tex-alphalph
BUILD_DEPENDS+=		tex-ec-[0-9]*:../../fonts/tex-ec
BUILD_DEPENDS+=		tex-psnfss-[0-9]*:../../fonts/tex-psnfss
BUILD_DEPENDS+=		tex-wasysym-[0-9]*:../../fonts/tex-wasysym
BUILD_DEPENDS+=		tex-adjustbox>=1.0nb1:../../print/tex-adjustbox
BUILD_DEPENDS+=		tex-caption-[0-9]*:../../print/tex-caption
BUILD_DEPENDS+=		tex-collectbox-[0-9]*:../../print/tex-collectbox
BUILD_DEPENDS+=		tex-colortbl-[0-9]*:../../print/tex-colortbl
BUILD_DEPENDS+=		tex-epstopdf-pkg-[0-9]*:../../print/tex-epstopdf-pkg
BUILD_DEPENDS+=		tex-etoc-[0-9]*:../../print/tex-etoc
BUILD_DEPENDS+=		tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
BUILD_DEPENDS+=		tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
BUILD_DEPENDS+=		tex-float-[0-9]*:../../print/tex-float
BUILD_DEPENDS+=		tex-geometry-[0-9]*:../../print/tex-geometry
BUILD_DEPENDS+=		tex-hanging-[0-9]*:../../print/tex-hanging
BUILD_DEPENDS+=		tex-hyperref-[0-9]*:../../print/tex-hyperref
BUILD_DEPENDS+=		tex-multirow-[0-9]*:../../print/tex-multirow
BUILD_DEPENDS+=		tex-natbib-[0-9]*:../../print/tex-natbib
BUILD_DEPENDS+=		tex-newunicodechar-[0-9]*:../../print/tex-newunicodechar
BUILD_DEPENDS+=		tex-oberdiek-[0-9]*:../../print/tex-oberdiek
BUILD_DEPENDS+=		tex-sectsty-[0-9]*:../../print/tex-sectsty
BUILD_DEPENDS+=		tex-stackengine-[0-9]*:../../print/tex-stackengine
BUILD_DEPENDS+=		tex-tabu-[0-9]*:../../print/tex-tabu
BUILD_DEPENDS+=		tex-tocloft-[0-9]*:../../print/tex-tocloft
BUILD_DEPENDS+=		tex-ulem-[0-9]*:../../print/tex-ulem
BUILD_DEPENDS+=		tex-xcolor-[0-9]*:../../print/tex-xcolor
BUILD_DEPENDS+=		tex-xkeyval-[0-9]*:../../print/tex-xkeyval
BUILD_DEPENDS+=		tex-xtab-[0-9]*:../../print/tex-xtab
BUILD_DEPENDS+=		makeindexk-[0-9]*:../../textproc/makeindexk
CONFIGURE_ARGS+=	--enable-doc
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-doxygen-doc
.endif
