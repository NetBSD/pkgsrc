# $NetBSD: Makefile,v 1.42 2014/05/09 07:37:04 wiz Exp $

DISTNAME=		lyx-2.0.7
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.lyx.org/pub/lyx/stable/2.0.x/ \
			http://gd.tuwien.ac.at/publishing/tex/lyx/stable/2.0.x/ \
			ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/2.0.x/ \
			ftp://ftp.sdsc.edu/pub/other/lyx/stable/2.0.x/ \
			ftp://ftp.lip6.fr/pub/lyx/stable/2.0.x/ \
			ftp://ftp.ntua.gr/pub/X11/LyX/stable/2.0.x/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.lyx.org/
COMMENT=		Document processor and graphical frontend for LaTeX
LICENSE=		gnu-gpl-v2

CONFLICTS+=		lyx-xforms-[0-9]* lyx-qt-[0-9]*
SUPERSEDES=		lyx-xforms-[0-9]* lyx-qt-[0-9]*
DEPENDS+=		makeindexk-[0-9]*:../../textproc/makeindexk
DEPENDS+=		tex-ae-[0-9]*:../../fonts/tex-ae
DEPENDS+=		tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=		tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=		tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=		tex-bera-[0-9]*:../../fonts/tex-bera
DEPENDS+=		tex-bezos-[0-9]*:../../print/tex-bezos
DEPENDS+=		tex-bibtex-[0-9]*:../../print/tex-bibtex
DEPENDS+=		tex-bibtopic-[0-9]*:../../print/tex-bibtopic
DEPENDS+=		tex-eco-[0-9]*:../../fonts/tex-eco
DEPENDS+=		tex-esint-[0-9]*:../../fonts/tex-esint
DEPENDS+=		tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=		tex-fourier-[0-9]*:../../fonts/tex-fourier
DEPENDS+=		tex-geometry-[0-9]*:../../print/tex-geometry
DEPENDS+=		tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=		tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=		tex-jurabib-[0-9]*:../../print/tex-jurabib
DEPENDS+=		tex-lastpage-[0-9]*:../../print/tex-lastpage
DEPENDS+=		tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=		tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=		tex-listings-[0-9]*:../../print/tex-listings
DEPENDS+=		tex-lm-[0-9]*:../../fonts/tex-lm
DEPENDS+=		tex-mhchem-[0-9]*:../../print/tex-mhchem
DEPENDS+=		tex-natbib-[0-9]*:../../print/tex-natbib
DEPENDS+=		tex-nomencl-[0-9]*:../../print/tex-nomencl
DEPENDS+=		tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=		tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=		tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=		tex-pst-node-[0-9]*:../../graphics/tex-pst-node
DEPENDS+=		tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=		tex-setspace-[0-9]*:../../print/tex-setspace
DEPENDS+=		tex-skak-[0-9]*:../../print/tex-skak
DEPENDS+=		tex-subfig-[0-9]*:../../print/tex-subfig
DEPENDS+=		tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=		tex-ulem-[0-9]*:../../print/tex-ulem
DEPENDS+=		tex-wasysym-[0-9]*:../../fonts/tex-wasysym
DEPENDS+=		tex-xargs-[0-9]*:../../print/tex-xargs
DEPENDS+=		tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=		tex-xypic-[0-9]*:../../graphics/tex-xypic

UNLIMIT_RESOURCES+=	datasize

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake perl:run pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.6.10

CXXFLAGS.Linux+=	-fpermissive

CONFIGURE_ARGS+=	--without-included-mythes

CONFIGURE_ARGS+=	--with-extra-prefix=${BUILDLINK_PREFIX.qt4-libs} \
			--with-qt4-dir=${QTDIR:Q} \
			--with-qt4-includes=${BUILDLINK_PREFIX.qt4-libs}/qt4/include \
			--with-qt4-libraries=${BUILDLINK_PREFIX.qt4-libs}/qt4/lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
GNU_CONFIGURE_PREFIX=	${PREFIX}/Applications/LyX.app
PLIST_SUBST+=		BIN_DIR=Applications/LyX.app/Contents/MacOS \
			LYX=LyX \
			MAN_DIR=Applications/LyX.app/Contents/Resources/man \
			SHARE_DIR=Applications/LyX.app/Contents/Resources
.else
PLIST_SUBST+=		BIN_DIR=bin \
			LYX=lyx \
			MAN_DIR="${PKGMANDIR}" \
			SHARE_DIR=share/lyx
.endif

REPLACE_PYTHON=	development/cmake/doc/ReplaceValues.py \
			development/cmake/po/cat.py \
			development/tools/convert_kmap.py \
			development/tools/gen_lfuns.py \
			development/tools/generate_symbols_list.py \
			development/tools/unicodesymbols.py \
			lib/configure.py \
			lib/lyx2lyx/lyx2lyx \
			lib/lyx2lyx/profiling.py \
			lib/scripts/TeXFiles.py \
			lib/scripts/clean_dvi.py \
			lib/scripts/convertDefault.py \
			lib/scripts/csv2lyx.py \
			lib/scripts/date.py \
			lib/scripts/ext_copy.py \
			lib/scripts/fen2ascii.py \
			lib/scripts/fig2pdftex.py \
			lib/scripts/fig2pstex.py \
			lib/scripts/fig_copy.py \
			lib/scripts/include_bib.py \
			lib/scripts/layout2layout.py \
			lib/scripts/legacy_lyxpreview2ppm.py \
			lib/scripts/listerrors \
			lib/scripts/lyxpak.py \
			lib/scripts/lyxpreview-lytex2bitmap.py \
			lib/scripts/lyxpreview-platex2bitmap.py \
			lib/scripts/lyxpreview2bitmap.py \
			lib/scripts/lyxpreview_tools.py \
			lib/scripts/tex_copy.py \
			lib/scripts/prefs2prefs.py \
			lib/scripts/prefs2prefs_lfuns.py \
			lib/scripts/prefs2prefs_prefs.py \
			po/lyx_pot.py \
			po/postats.py

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	lib/configure.py
SUBST_SED.python=	-e "s,python ,${PYTHONBIN} ,"
SUBST_FILES.python+=	src/graphics/GraphicsConverter.cpp
SUBST_SED.python+=	-e "s,\#!/usr/bin/env python,\#!${PYTHONBIN},"
SUBST_FILES.python+=	lib/scripts/lyxpak.py
SUBST_FILES.python+=	development/scons/SConstruct
SUBST_SED.python+=	-e "s, = 'python, = '${PYTHONBIN},"
SUBST_FILES.python+=	src/support/os.cpp
SUBST_SED.python+=	-e 's,command("python -tt,command("${PYTHONBIN} -tt,'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../textproc/mythes/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
