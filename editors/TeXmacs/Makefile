# $NetBSD: Makefile,v 1.128 2019/08/11 13:20:53 wiz Exp $
#
# changelog at http://www.texmacs.org/tmweb/about/changes.en.html

DISTNAME=		TeXmacs-1.99.5-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		14
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.texmacs.org/pub/TeXmacs/tmftp/source/
MASTER_SITES+=		http://www.texmacs.org/Download/ftp/tmftp/source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.texmacs.org/
COMMENT=		GNU TeXmacs (free scientific text editor)

DEPENDS+=		ps2pkm>=1.5:../../fonts/ps2pkm

BUILD_TARGET=		TEXMACS

USE_TOOLS+=		gmake perl:run pkg-config bash
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_RCC=${QTDIR}/bin/rcc
# XXX workaround for bug in configure
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--with-qt=${QTDIR}
BUILD_MAKE_FLAGS+=	QT_QTDIR=${QTDIR}

# in 1.99.5 this fails with
# ./configure: 4562: Syntax error: Bad substitution
CONFIG_SHELL=		${BASH}

REPLACE_PYTHON=		plugins/python/bin/tm_python
REPLACE_PYTHON+=	plugins/sage/bin/tm_sage
REPLACE_PYTHON+=	plugins/mathematica/bin/realpath.py

SUBST_CLASSES+=		init
SUBST_STAGE.init=	pre-configure
SUBST_FILES.init=	plugins/python/progs/init-python.scm
SUBST_VARS.init=	PYTHONBIN

REPLACE_SH+=		plugins/asymptote/bin/tm_asy
REPLACE_SH+=		plugins/dratex/bin/tm_dratex
REPLACE_SH+=		plugins/eukleides/bin/tm_eukleides
REPLACE_SH+=		plugins/eukleides/bin/tm_eukleides.old
REPLACE_SH+=		plugins/gnuplot/bin/tm_gnuplot
REPLACE_SH+=		plugins/lisp/bin/tm_lisp
REPLACE_SH+=		plugins/lush/bin/tm_lush
REPLACE_SH+=		plugins/matlab/bin/tm_matlab
REPLACE_SH+=		plugins/maxima/bin/maxima_detect
REPLACE_SH+=		plugins/maxima/bin/tm_maxima
REPLACE_SH+=		plugins/mupad/bin/tm_mupad
REPLACE_SH+=		plugins/mupad/bin/tm_mupad_help
REPLACE_SH+=		plugins/octave/bin/tm_octave
REPLACE_SH+=		plugins/reduce/bin/tm_reduce
REPLACE_SH+=		plugins/texgraph/bin/tm_texgraph
REPLACE_SH+=		plugins/xypic/bin/tm_xypic
REPLACE_SH+=		misc/admin/sign_update
REPLACE_SH+=		misc/scripts/gs

REPLACE_PERL+=		plugins/asymptote/bin/perl-tm_asy
REPLACE_PERL+=		plugins/asymptote/bin/tm_asy2
REPLACE_PERL+=		plugins/feynmf/bin/bbox_add.pl

SUBST_CLASSES+=		linkpath
SUBST_SED.linkpath+=	-e "s,-lguile,-L${PREFIX}/guile/1.8/lib -lguile,g"
SUBST_FILES.linkpath+=	configure
SUBST_MESSAGE.linkpath=	Search for guile library in proper directory.
SUBST_STAGE.linkpath=	pre-configure

SUBST_CLASSES+=		bash
SUBST_SED.bash+=	-e "s,/bin/bash,${PREFIX}/bin/bash,"
SUBST_FILES.bash+=	src/makefile.in src/Texmacs/Texmacs/texmacs.cpp Makefile.in
SUBST_MESSAGE.bash=	Fixing hardcoded bash path.
SUBST_STAGE.bash=	pre-configure

pre-build:
	find ${WRKSRC} -name ._* -exec rm {} \;

# do not install backup files
post-install:
	${RM} ${DESTDIR}${PREFIX}/share/TeXmacs/plugins/python/progs/init-python.scm.orig

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
# as of 1.99.5
# configure: error: TeXmacs is incompatible with Guile 2.
#.include "../../lang/guile20/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../print/ghostscript/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
