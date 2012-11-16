# $NetBSD: options.mk,v 1.1 2012/11/16 14:44:22 jaapb Exp $

PKG_OPTIONS_VAR= PKG_OPTIONS.coq
PKG_SUPPORTED_OPTIONS= doc coqide
PKG_SUGGESTED_OPTIONS= coqide

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
DEPENDS+= hevea>=1.10:../../textproc/hevea
CONFIGURE_ARGS+=	-with-doc yes
PLIST.doc=		yes
BUILD_DEPENDS+=		tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+=		makeindexk-[0-9]*:../../textproc/makeindexk
BUILD_DEPENDS+=		dvipsk-[0-9]*:../../print/dvipsk
BUILD_DEPENDS+=		tex-babel-[0-9]*:../../print/tex-babel
BUILD_DEPENDS+=		tex-bibtex-[0-9]*:../../print/tex-bibtex
BUILD_DEPENDS+=		tex-cm-super-[0-9]*:../../fonts/tex-cm-super
BUILD_DEPENDS+=		tex-comment-[0-9]*:../../print/tex-comment
BUILD_DEPENDS+=		tex-ec-[0-9]*:../../fonts/tex-ec
BUILD_DEPENDS+=		tex-eepic-[0-9]*:../../graphics/tex-eepic
BUILD_DEPENDS+=		tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
BUILD_DEPENDS+=		tex-index-[0-9]*:../../print/tex-index
BUILD_DEPENDS+=		tex-moreverb-[0-9]*:../../print/tex-moreverb
BUILD_DEPENDS+=		tex-multirow-[0-9]*:../../print/tex-multirow
BUILD_DEPENDS+=		tex-preprint-[0-9]*:../../print/tex-preprint
BUILD_DEPENDS+=		tex-pslatex-[0-9]*:../../print/tex-pslatex
BUILD_DEPENDS+=		tex-psnfss-[0-9]*:../../fonts/tex-psnfss
BUILD_DEPENDS+=		tex-stmaryrd-[0-9]*:../../fonts/tex-stmaryrd
BUILD_DEPENDS+=		tex-ucs-[0-9]*:../../print/tex-ucs
BUILD_DEPENDS+=		tex-xcolor-[0-9]*:../../print/tex-xcolor
.else
CONFIGURE_ARGS+= -with-doc no
.endif

.if !empty(PKG_OPTIONS:Mcoqide)
.include "../../x11/lablgtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
PLIST.coqide=		yes
.else
CONFIGURE_ARGS+= -coqide no
.endif
