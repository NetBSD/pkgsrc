# $NetBSD: Makefile,v 1.124 2024/05/29 16:32:24 adam Exp $

DISTNAME=		lyx-2.3.6.1
PKGREVISION=		21
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.lyx.org/pub/lyx/stable/2.3.x/
MASTER_SITES+=		ftp://ftp.sdsc.edu/pub/other/lyx/stable/2.3.x/
MASTER_SITES+=		ftp://ftp.lip6.fr/pub/lyx/stable/2.3.x/
MASTER_SITES+=		ftp://ftp.ntua.gr/pub/X11/LyX/stable/2.3.x/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		https://www.lyx.org/
COMMENT=		Document processor and graphical frontend for LaTeX
LICENSE=		gnu-gpl-v2

CONFLICTS+=		lyx-xforms-[0-9]* lyx-qt-[0-9]*
SUPERSEDES=		lyx-xforms-[0-9]* lyx-qt-[0-9]*
DEPENDS+=		makeindexk-[0-9]*:../../textproc/makeindexk
DEPENDS+=		tex-accents-[0-9]*:../../print/tex-accents
DEPENDS+=		tex-ae-[0-9]*:../../fonts/tex-ae
DEPENDS+=		tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=		tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=		tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=		tex-bera-[0-9]*:../../fonts/tex-bera
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

USE_LANGUAGES=			c c++
GNU_CONFIGURE=			YES
USE_TOOLS+=			gmake perl:run pkg-config xgettext
USE_LIBTOOL=			YES
USE_PKGLOCALEDIR=		YES

CXXFLAGS.Linux+=	-fpermissive

CONFIGURE_ARGS+=	--without-included-mythes
CONFIGURE_ARGS+=	--without-included-boost

CONFIGURE_ARGS+=	--with-extra-prefix=${BUILDLINK_PREFIX.qt5-qtbase} \
			--with-qt-dir=${QTDIR:Q} \
			--with-qt-includes=${BUILDLINK_PREFIX.qt5-qtbase}/qt5/include \
			--with-qt-libraries=${BUILDLINK_PREFIX.qt5-qtbase}/qt5/lib \
			--enable-qt5

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		x11

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
PLIST.x11=		yes
.endif

PRINT_PLIST_AWK+=	{ sub(/bin\//, "$${BIN_DIR}/"); \
				sub(/^share\/lyx\//, "$${SHARE_DIR}/"); \
				gsub(/LC_MESSAGES\/lyx./, "LC_MESSAGES/$${LYX}."); \
				sub(/^${PKGMANDIR}\//, "$${MAN_DIR}/"); \
				print; next; }

REPLACE_PYTHON=	development/autotests/keytest.py \
			development/cmake/doc/ReplaceValues.py \
			development/cmake/po/cat.py \
			development/cmake/po/unix2dos.py \
			development/keystest/cache-bisect.py \
			development/keystest/make_screenshot_html.py \
			development/keystest/keytest.py \
			development/tools/gen_lfuns.py \
			development/tools/generate_symbols_images.py \
			development/tools/generate_symbols_list.py \
			development/tools/unicodesymbols.py \
			lib/configure.py \
			lib/lyx2lyx/*.py \
			lib/lyx2lyx/lyx2lyx \
			lib/scripts/*.py \
			lib/scripts/listerrors \
			po/lyx_pot.py \
			po/postats.py \
			src/tex2lyx/test/runtests.py

# Replacing plain "python " with PYTHONBIN replaces a few instances too
# many, but nothing critical. Set SUBST_SHOW_DIFF=yes to see them.
SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	lib/configure.py
SUBST_SED.python=	-e "s,python ,${PYTHONBIN} ,"
SUBST_FILES.python+=	src/graphics/GraphicsConverter.cpp
SUBST_SED.python+=	-e "s,\#!/usr/bin/env python,\#!${PYTHONBIN},"
SUBST_FILES.python+=	lib/scripts/lyxpak.py
SUBST_SED.python+=	-e "s, = 'python, = '${PYTHONBIN},"
SUBST_FILES.python+=	src/support/os.cpp
SUBST_SED.python+=	-e 's,command("python -tt,command("${PYTHONBIN} -tt,'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"   # for PLIST handling
.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../textproc/mythes/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
