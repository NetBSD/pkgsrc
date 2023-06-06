# $NetBSD: options.mk,v 1.12 2023/06/06 12:41:57 riastradh Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libcarddav
PKG_SUPPORTED_OPTIONS=		doc
PKG_SUGGESTED_OPTIONS=		# empty
PKG_OPTIONS_LEGACY_OPTS+=	doxygen:doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc

.if !empty(PKG_OPTIONS:Mdoc)
TOOL_DEPENDS+=		doxygen>=1.8.1.1:../../devel/doxygen
TOOL_DEPENDS+=		tex-alphalph-[0-9]*:../../print/tex-alphalph
TOOL_DEPENDS+=		tex-ec-[0-9]*:../../fonts/tex-ec
TOOL_DEPENDS+=		tex-psnfss-[0-9]*:../../fonts/tex-psnfss
TOOL_DEPENDS+=		tex-wasysym-[0-9]*:../../fonts/tex-wasysym
TOOL_DEPENDS+=		tex-adjustbox>=1.0nb1:../../print/tex-adjustbox
TOOL_DEPENDS+=		tex-caption-[0-9]*:../../print/tex-caption
TOOL_DEPENDS+=		tex-collectbox-[0-9]*:../../print/tex-collectbox
TOOL_DEPENDS+=		tex-colortbl-[0-9]*:../../print/tex-colortbl
TOOL_DEPENDS+=		tex-epstopdf-pkg-[0-9]*:../../print/tex-epstopdf-pkg
TOOL_DEPENDS+=		tex-etoc-[0-9]*:../../print/tex-etoc
TOOL_DEPENDS+=		tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
TOOL_DEPENDS+=		tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
TOOL_DEPENDS+=		tex-float-[0-9]*:../../print/tex-float
TOOL_DEPENDS+=		tex-geometry-[0-9]*:../../print/tex-geometry
TOOL_DEPENDS+=		tex-hanging-[0-9]*:../../print/tex-hanging
TOOL_DEPENDS+=		tex-hyperref-[0-9]*:../../print/tex-hyperref
TOOL_DEPENDS+=		tex-multirow-[0-9]*:../../print/tex-multirow
TOOL_DEPENDS+=		tex-natbib-[0-9]*:../../print/tex-natbib
TOOL_DEPENDS+=		tex-newunicodechar-[0-9]*:../../print/tex-newunicodechar
TOOL_DEPENDS+=		tex-oberdiek-[0-9]*:../../print/tex-oberdiek
TOOL_DEPENDS+=		tex-sectsty-[0-9]*:../../print/tex-sectsty
TOOL_DEPENDS+=		tex-stackengine-[0-9]*:../../print/tex-stackengine
TOOL_DEPENDS+=		tex-tabu-[0-9]*:../../print/tex-tabu
TOOL_DEPENDS+=		tex-tocloft-[0-9]*:../../print/tex-tocloft
TOOL_DEPENDS+=		tex-ulem-[0-9]*:../../print/tex-ulem
TOOL_DEPENDS+=		tex-xcolor-[0-9]*:../../print/tex-xcolor
TOOL_DEPENDS+=		tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TOOL_DEPENDS+=		tex-xtab-[0-9]*:../../print/tex-xtab
TOOL_DEPENDS+=		makeindexk-[0-9]*:../../textproc/makeindexk
CONFIGURE_ARGS+=	--enable-doc
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-doxygen-doc
.endif
