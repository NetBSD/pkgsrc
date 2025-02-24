# $NetBSD: options.mk,v 1.18 2025/02/24 03:41:02 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.coq
PKG_SUPPORTED_OPTIONS=	doc coqide
PKG_SUGGESTED_OPTIONS=	coqide

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		coqide doc

.if !empty(PKG_OPTIONS:Mdoc)
#DUNE_BUILD_PACKAGES+=		@refman-html @refman-pdf @stdlib-html
#OPAM_INSTALL_FILES+=		@refman-html @refman-pdf @stdlib-html
DUNE_BUILD_PACKAGES+=		coq-doc
OPAM_INSTALL_FILES+=		coq-doc
PLIST.doc=			yes

TOOL_DEPENDS+=			hevea>=1.10:../../textproc/hevea

#
# python
#

PYTHON_VERSIONS_INCOMPATIBLE=	39 310 # py-sphinx

.include "../../lang/python/tool.mk"
SUBST_CLASSES+=			sphinx-build
SUBST_STAGE.sphinx-build=	pre-configure
SUBST_MESSAGE.sphinx-build=	Fix hardcoded sphinx-build
SUBST_FILES.sphinx-build+=	doc/dune
SUBST_SED.sphinx-build+=	-e 's/sphinx-build/sphinx-build-${PYVERSSUFFIX}/g'

# The sphinx build is set up to default to -W (basically -Werror), and
# fails that way. You can't set it to empty, though, that causes dune
# to pass '' to sphinx and that confuses sphinx. Pass something harmless
# instead.
MAKE_ENV+=			SPHINXWARNOPT=--no-color

#
# sphinx
#

TOOL_DEPENDS+=			py[0-9]*-sphinx-[0-9]*:../../textproc/py-sphinx
TOOL_DEPENDS+=			py[0-9]*-sphinx-rtd-theme-[0-9]*:../../textproc/py-sphinx-rtd-theme
TOOL_DEPENDS+=			py[0-9]*-sphinxcontrib-bibtex-[0-9]*:../../textproc/py-sphinxcontrib-bibtex
TOOL_DEPENDS+=			py[0-9]*-pybtex-[0-9]*:../../textproc/py-pybtex
TOOL_DEPENDS+=			py[0-9]*-pybtex-docutils-[0-9]*:../../textproc/py-pybtex-docutils
TOOL_DEPENDS+=			py[0-9]*-pexpect-[0-9]*:../../devel/py-pexpect
TOOL_DEPENDS+=			py[0-9]*-antlr4-[0-9]*:../../textproc/py-antlr4
TOOL_DEPENDS+=			py[0-9]*-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4

#
# tex
#

TOOL_DEPENDS+=			latexmk-[0-9]*:../../print/latexmk
TOOL_DEPENDS+=			tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TOOL_DEPENDS+=			tex-moreverb-[0-9]*:../../print/tex-moreverb
TOOL_DEPENDS+=			tex-preprint-[0-9]*:../../print/tex-preprint
TOOL_DEPENDS+=			tex-ucs-[0-9]*:../../print/tex-ucs
TOOL_DEPENDS+=			tex-xetex-[0-9]*:../../print/tex-xetex
TOOL_DEPENDS+=			tex-polyglossia-[0-9]*:../../print/tex-polyglossia
TOOL_DEPENDS+=			tex-fncychap-[0-9]*:../../print/tex-fncychap
TOOL_DEPENDS+=			tex-tabulary-[0-9]*:../../print/tex-tabulary
TOOL_DEPENDS+=			tex-varwidth-[0-9]*:../../print/tex-varwidth
TOOL_DEPENDS+=			tex-parskip-[0-9]*:../../print/tex-parskip
TOOL_DEPENDS+=			tex-upquote-[0-9]*:../../print/tex-upquote
TOOL_DEPENDS+=			tex-capt-of-[0-9]*:../../print/tex-capt-of
TOOL_DEPENDS+=			tex-needspace-[0-9]*:../../print/tex-needspace
TOOL_DEPENDS+=			tex-unicode-math-[0-9]*:../../math/tex-unicode-math
TOOL_DEPENDS+=			tex-microtype-[0-9]*:../../print/tex-microtype
TOOL_DEPENDS+=			tex-adjustbox-[0-9]*:../../print/tex-adjustbox
TOOL_DEPENDS+=			tex-xindy-[0-9]*:../../textproc/tex-xindy
TOOL_DEPENDS+=			tex-ec-[0-9]*:../../fonts/tex-ec
TOOL_DEPENDS+=			tex-xcolor-[0-9]*:../../print/tex-xcolor
TOOL_DEPENDS+=			tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TOOL_DEPENDS+=			tex-titlesec-[0-9]*:../../print/tex-titlesec
TOOL_DEPENDS+=			tex-framed-[0-9]*:../../print/tex-framed
TOOL_DEPENDS+=			tex-float-[0-9]*:../../print/tex-float
TOOL_DEPENDS+=			tex-wrapfig-[0-9]*:../../print/tex-wrapfig
TOOL_DEPENDS+=			tex-lm-math-[0-9]*:../../fonts/tex-lm-math
TOOL_DEPENDS+=			tex-gnu-freefont-[0-9]*:../../fonts/tex-gnu-freefont
TOOL_DEPENDS+=			dvipsk-[0-9]*:../../print/dvipsk
.endif

.if !empty(PKG_OPTIONS:Mcoqide)
BUILDLINK_API_DEPENDS.ocaml-lablgtk3+=	ocaml-lablgtk3>=3.1.2
.include "../../x11/ocaml-lablgtk3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
DEPENDS+=	adwaita-icon-theme-[0-9]*:../../graphics/adwaita-icon-theme
DUNE_BUILD_PACKAGES+=	coqide-server coqide
OPAM_INSTALL_FILES+=	coqide-server coqide
PLIST.coqide=		yes
.endif
