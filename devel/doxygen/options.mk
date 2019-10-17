# $NetBSD: options.mk,v 1.14 2019/10/17 20:35:58 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.doxygen
PKG_SUPPORTED_OPTIONS=	latex qt

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		latex qt

.if !empty(PKG_OPTIONS:Mlatex)
CMAKE_ARGS+=	-Dbuild_doc=ON
BUILD_TARGET=	all docs
PLIST.latex=	yes

# XXX Clearly separate what is build time vs runtime, and move
# build-time dependencies into USE_TOOLS framework.

BUILD_DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	makeindexk-[0-9]*:../../textproc/makeindexk
DEPENDS+=	tex-a4wide>=2010nb1:../../print/tex-a4wide
DEPENDS+=	tex-cm-super-[0-9]*:../../fonts/tex-cm-super
DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
DEPENDS+=	tex-epstopdf-[0-9]*:../../graphics/tex-epstopdf
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-rsfs-[0-9]*:../../fonts/tex-rsfs

#
# Styles used by Doxygen output.
#
DEPENDS+=	tex-adjustbox-[0-9]*:../../print/tex-adjustbox
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-appendix-[0-9]*:../../print/tex-appendix
DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-etoc-[0-9]*:../../print/tex-etoc
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hanging-[0-9]*:../../print/tex-hanging
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-import-[0-9]*:../../print/tex-import
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
DEPENDS+=	tex-listofitems-[0-9]*:../../print/tex-listofitems
DEPENDS+=	tex-multirow-[0-9]*:../../print/tex-multirow
DEPENDS+=	tex-newunicodechar-[0-9]*:../../print/tex-newunicodechar
DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-psnfss>=9.2anb2:../../fonts/tex-psnfss
DEPENDS+=	tex-pspicture-[0-9]*:../../print/tex-pspicture
DEPENDS+=	tex-sectsty-[0-9]*:../../print/tex-sectsty
DEPENDS+=	tex-stackengine-[0-9]*:../../print/tex-stackengine
DEPENDS+=	tex-tabu-[0-9]*:../../print/tex-tabu
DEPENDS+=	tex-tocloft-[0-9]*:../../print/tex-tocloft
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-ulem-[0-9]*:../../print/tex-ulem
DEPENDS+=	tex-wasysym-[0-9]*:../../fonts/tex-wasysym
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xtab-[0-9]*:../../print/tex-xtab
.endif


.if !empty(PKG_OPTIONS:Mqt)
CMAKE_ARGS+=	-Dbuild_wizard=ON
PLIST.qt=	yes
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif
