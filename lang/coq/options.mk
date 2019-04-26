# $NetBSD: options.mk,v 1.6 2019/04/26 12:44:43 roy Exp $

PKG_OPTIONS_VAR= PKG_OPTIONS.coq
PKG_SUPPORTED_OPTIONS= doc coqide
PKG_SUGGESTED_OPTIONS= coqide

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
PYTHON_VERSIONS_ACCEPTED=	37 36
CONFIGURE_ARGS+=	-with-doc yes
PLIST.doc=		yes
BUILD_DEPENDS+=		tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+= hevea>=1.10:../../textproc/hevea
BUILD_DEPENDS+=		tex-moreverb-[0-9]*:../../print/tex-moreverb
BUILD_DEPENDS+=		tex-preprint-[0-9]*:../../print/tex-preprint
BUILD_DEPENDS+=		tex-ucs-[0-9]*:../../print/tex-ucs
BUILD_DEPENDS+=		py[0-9]*-sphinx-[0-9]*:../../textproc/py-sphinx
BUILD_DEPENDS+=		py[0-9]*-sphinx-rtd-theme-[0-9]*:../../textproc/py-sphinx-rtd-theme
BUILD_DEPENDS+=		py[0-9]*-sphinxcontrib-bibtex-[0-9]*:../../textproc/py-sphinxcontrib-bibtex
BUILD_DEPENDS+=		py[0-9]*-pybtex-[0-9]*:../../textproc/py-pybtex
BUILD_DEPENDS+=		py[0-9]*-pybtex-docutils-[0-9]*:../../textproc/py-pybtex-docutils
BUILD_DEPENDS+=		py[0-9]*-pexpect-[0-9]*:../../devel/py-pexpect
BUILD_DEPENDS+=		py[0-9]*-antlr4-[0-9]*:../../textproc/py-antlr4
BUILD_DEPENDS+=		py[0-9]*-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
BUILD_DEPENDS+=		latexmk-[0-9]*:../../print/latexmk
BUILD_DEPENDS+=		tex-xetex-[0-9]*:../../print/tex-xetex
BUILD_DEPENDS+=		tex-polyglossia-[0-9]*:../../print/tex-polyglossia
BUILD_DEPENDS+=		tex-fncychap-[0-9]*:../../print/tex-fncychap
BUILD_DEPENDS+=		tex-tabulary-[0-9]*:../../print/tex-tabulary
BUILD_DEPENDS+=		tex-varwidth-[0-9]*:../../print/tex-varwidth
BUILD_DEPENDS+=		tex-parskip-[0-9]*:../../print/tex-parskip
BUILD_DEPENDS+=		tex-upquote-[0-9]*:../../print/tex-upquote
BUILD_DEPENDS+=		tex-capt-of-[0-9]*:../../print/tex-capt-of
BUILD_DEPENDS+=		tex-needspace-[0-9]*:../../print/tex-needspace
BUILD_DEPENDS+=		tex-unicode-math-[0-9]*:../../math/tex-unicode-math
BUILD_DEPENDS+=		tex-microtype-[0-9]*:../../print/tex-microtype
BUILD_DEPENDS+=		tex-adjustbox-[0-9]*:../../print/tex-adjustbox
BUILD_DEPENDS+=		tex-xindy-[0-9]*:../../textproc/tex-xindy
BUILD_DEPENDS+=		tex-ec-[0-9]*:../../fonts/tex-ec
BUILD_DEPENDS+=		tex-xcolor-[0-9]*:../../print/tex-xcolor
BUILD_DEPENDS+=		tex-xkeyval-[0-9]*:../../print/tex-xkeyval
BUILD_DEPENDS+=		tex-titlesec-[0-9]*:../../print/tex-titlesec
BUILD_DEPENDS+=		tex-framed-[0-9]*:../../print/tex-framed
BUILD_DEPENDS+=		tex-float-[0-9]*:../../print/tex-float
BUILD_DEPENDS+=		tex-wrapfig-[0-9]*:../../print/tex-wrapfig
BUILD_DEPENDS+=		tex-lm-math-[0-9]*:../../fonts/tex-lm-math
BUILD_DEPENDS+=		dvipsk-[0-9]*:../../print/dvipsk
.else
CONFIGURE_ARGS+= -with-doc no
.endif

.if !empty(PKG_OPTIONS:Mcoqide)
.include "../../x11/ocaml-lablgtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
PLIST.coqide=		yes
.else
CONFIGURE_ARGS+= -coqide no
.endif
