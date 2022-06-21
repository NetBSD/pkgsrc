# $NetBSD: options.mk,v 1.13 2022/06/21 02:21:22 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.coq
PKG_SUPPORTED_OPTIONS=	doc coqide
PKG_SUGGESTED_OPTIONS=	coqide

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
CONFIGURE_ARGS+=		-with-doc yes
PLIST.doc=			yes

BUILD_DEPENDS+=			hevea>=1.10:../../textproc/hevea

#
# python
#

PYTHON_VERSIONS_INCOMPATIBLE=	27
.include "../../lang/python/tool.mk"
SUBST_CLASSES+=			sphinx-build
SUBST_STAGE.sphinx-build=	pre-configure
SUBST_MESSAGE.sphinx-build=	Fix hardcoded sphinx-build
SUBST_FILES.sphinx-build+=	Makefile.doc configure.ml doc/dune
SUBST_SED.sphinx-build+=	-e 's/sphinx-build/sphinx-build-${PYVERSSUFFIX}/g'

TOOL_DEPENDS+=			py[0-9]*-sphinx-[0-9]*:../../textproc/py-sphinx
BUILD_DEPENDS+=			py[0-9]*-sphinx-rtd-theme-[0-9]*:../../textproc/py-sphinx-rtd-theme
BUILD_DEPENDS+=			py[0-9]*-sphinxcontrib-bibtex-[0-9]*:../../textproc/py-sphinxcontrib-bibtex
BUILD_DEPENDS+=			py[0-9]*-pybtex-[0-9]*:../../textproc/py-pybtex
BUILD_DEPENDS+=			py[0-9]*-pybtex-docutils-[0-9]*:../../textproc/py-pybtex-docutils
BUILD_DEPENDS+=			py[0-9]*-pexpect-[0-9]*:../../devel/py-pexpect
BUILD_DEPENDS+=			py[0-9]*-antlr4-[0-9]*:../../textproc/py-antlr4
BUILD_DEPENDS+=			py[0-9]*-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4

#
# tex
#

BUILD_DEPENDS+=			latexmk-[0-9]*:../../print/latexmk
BUILD_DEPENDS+=			tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+=			tex-moreverb-[0-9]*:../../print/tex-moreverb
BUILD_DEPENDS+=			tex-preprint-[0-9]*:../../print/tex-preprint
BUILD_DEPENDS+=			tex-ucs-[0-9]*:../../print/tex-ucs
BUILD_DEPENDS+=			tex-xetex-[0-9]*:../../print/tex-xetex
BUILD_DEPENDS+=			tex-polyglossia-[0-9]*:../../print/tex-polyglossia
BUILD_DEPENDS+=			tex-fncychap-[0-9]*:../../print/tex-fncychap
BUILD_DEPENDS+=			tex-tabulary-[0-9]*:../../print/tex-tabulary
BUILD_DEPENDS+=			tex-varwidth-[0-9]*:../../print/tex-varwidth
BUILD_DEPENDS+=			tex-parskip-[0-9]*:../../print/tex-parskip
BUILD_DEPENDS+=			tex-upquote-[0-9]*:../../print/tex-upquote
BUILD_DEPENDS+=			tex-capt-of-[0-9]*:../../print/tex-capt-of
BUILD_DEPENDS+=			tex-needspace-[0-9]*:../../print/tex-needspace
BUILD_DEPENDS+=			tex-unicode-math-[0-9]*:../../math/tex-unicode-math
BUILD_DEPENDS+=			tex-microtype-[0-9]*:../../print/tex-microtype
BUILD_DEPENDS+=			tex-adjustbox-[0-9]*:../../print/tex-adjustbox
BUILD_DEPENDS+=			tex-xindy-[0-9]*:../../textproc/tex-xindy
BUILD_DEPENDS+=			tex-ec-[0-9]*:../../fonts/tex-ec
BUILD_DEPENDS+=			tex-xcolor-[0-9]*:../../print/tex-xcolor
BUILD_DEPENDS+=			tex-xkeyval-[0-9]*:../../print/tex-xkeyval
BUILD_DEPENDS+=			tex-titlesec-[0-9]*:../../print/tex-titlesec
BUILD_DEPENDS+=			tex-framed-[0-9]*:../../print/tex-framed
BUILD_DEPENDS+=			tex-float-[0-9]*:../../print/tex-float
BUILD_DEPENDS+=			tex-wrapfig-[0-9]*:../../print/tex-wrapfig
BUILD_DEPENDS+=			tex-lm-math-[0-9]*:../../fonts/tex-lm-math
BUILD_DEPENDS+=			tex-gnu-freefont-[0-9]*:../../fonts/tex-gnu-freefont
BUILD_DEPENDS+=			dvipsk-[0-9]*:../../print/dvipsk
.else
CONFIGURE_ARGS+=		-with-doc no
.endif

.if !empty(PKG_OPTIONS:Mcoqide)
BUILDLINK_API_DEPENDS.ocaml-lablgtk3+=	ocaml-lablgtk3>=3.1.0
.include "../../x11/ocaml-lablgtk3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
DEPENDS+=	adwaita-icon-theme-[0-9]*:../../graphics/adwaita-icon-theme
CONFIGURE_ARGS+=	-coqide ${COQIDE_TYPE}
PLIST.coqide=		yes
.else
CONFIGURE_ARGS+= -coqide no
.endif
