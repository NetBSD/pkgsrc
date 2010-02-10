# $NetBSD: Makefile,v 1.4 2010/02/10 19:17:37 joerg Exp $
#

DISTNAME=		lyx-1.6.4.1
PKGREVISION=		2
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.lyx.org/pub/lyx/stable/1.6.x/ \
			http://gd.tuwien.ac.at/publishing/tex/lyx/stable/1.6.x/ \
			ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/1.6.x/ \
			ftp://ftp.sdsc.edu/pub/other/lyx/stable/1.6.x/ \
			ftp://ftp.lip6.fr/pub/lyx/stable/1.6.x/ \
			ftp://ftp.ntua.gr/pub/X11/LyX/stable/1.6.x/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.lyx.org/
COMMENT=		Document processor and graphical frontend for LaTeX

CONFLICTS+=		lyx-xforms-[0-9]* lyx-qt-[0-9]*
SUPERSEDES=		lyx-xforms-[0-9]* lyx-qt-[0-9]*

UNLIMIT_RESOURCES+=	datasize

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake perl:run pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
GCC_REQD+=		2.95
TEX_ACCEPTED=		teTeX3
MAKE_ENV+=		PKG_LOCALTEXMFPREFIX=${PKG_LOCALTEXMFPREFIX}

CONFIGURE_ARGS+=	--with-extra-prefix=${BUILDLINK_PREFIX.qt4-libs} \
			--with-qt4-dir=${QTDIR:Q} \
			--with-qt4-includes=${BUILDLINK_PREFIX.qt4-libs}/qt4/include \
			--with-qt4-libraries=${BUILDLINK_PREFIX.qt4-libs}/qt4/lib

CONFIGURE_ARGS+=	--with-pspell-lib=${BUILDLINK_PREFIX.aspell}/lib \
			--with-pspell-include=${BUILDLINK_PREFIX.aspell}/include/pspell \
			--with-pspell

PYTHON_PATCH_SCRIPTS=	development/tools/convert_kmap.py \
			development/tools/generate_symbols_list.py \
			development/tools/lyxpak.py \
			development/tools/lyxpak.py \
			development/tools/unicodesymbols.py \
			lib/configure.py \
			lib/doc/depend.py \
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
			lib/scripts/layout2layout.py \
			lib/scripts/legacy_lyxpreview2ppm.py \
			lib/scripts/listerrors \
			lib/scripts/lyxpreview-platex2bitmap.py \
			lib/scripts/lyxpreview2bitmap.py \
			lib/scripts/lyxpreview_tools.py \
			lib/scripts/tex_copy.py \
			po/lyx_pot.py \
			po/postats.py

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	lib/configure.py
SUBST_SED.python=	-e "s,python ,${PYTHONBIN} ,"
SUBST_FILES.python+=	src/graphics/GraphicsConverter.cpp
SUBST_SED.python+=	-e "s,\#!/usr/bin/env python,\#!${PYTHONBIN},"
SUBST_FILES.python+=	development/tools/lyxpak.py
SUBST_FILES.python+=	development/scons/SConstruct
SUBST_SED.python+=	-e "s, = 'python, = '${PYTHONBIN},"
SUBST_FILES.python+=	src/support/os.cpp
SUBST_SED.python+=	-e 's,command("python -tt,command("${PYTHONBIN} -tt,'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../print/teTeX/module.mk"
.include "../../textproc/aiksaurus/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
