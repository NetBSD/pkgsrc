# $NetBSD: options.mk,v 1.10 2014/05/12 03:10:57 minskim Exp $
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.doxygen
PKG_SUPPORTED_OPTIONS=	latex
PKG_SUGGESTED_OPTIONS=	latex

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		latex

.if !empty(PKG_OPTIONS:Mlatex)
PLIST.latex=		yes

INSTALL_TARGET+=	install_docs

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
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
DEPENDS+=	tex-multirow-[0-9]*:../../print/tex-multirow
DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-psnfss>=9.2anb2:../../fonts/tex-psnfss
DEPENDS+=	tex-pspicture-[0-9]*:../../print/tex-pspicture
DEPENDS+=	tex-sectsty-[0-9]*:../../print/tex-sectsty
DEPENDS+=	tex-tocloft-[0-9]*:../../print/tex-tocloft
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-wasysym-[0-9]*:../../fonts/tex-wasysym
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xtab-[0-9]*:../../print/tex-xtab

.endif
