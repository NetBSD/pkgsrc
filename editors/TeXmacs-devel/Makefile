# $NetBSD: Makefile,v 1.13.2.1 2012/10/03 12:07:26 spz Exp $

DISTNAME=		TeXmacs-1.0.7.16-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		3
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.texmacs.org/TeXmacs/tmftp/source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.texmacs.org/
COMMENT=		GNU TeXmacs (free scientific text editor)

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		TEXMACS

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
# XXX workaround for bug in configure
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--with-qt=${QTDIR}/bin
MAKE_ENV+=		QT_QTDIR=${QTDIR}
TEX_ACCEPTED=		teTeX3

PYTHON_PATCH_SCRIPTS=	plugins/python/bin/tm_python
PYTHON_PATCH_SCRIPTS+=	plugins/mathematica/bin/realpath.py
PYTHON_PATCH_SCRIPTS+=	plugins/sage/bin/tm_sage

SUBST_CLASSES+=		init
SUBST_STAGE.init=	post-patch
SUBST_FILES.init=	plugins/python/progs/init-python.scm
SUBST_SED.init=		-e 's,@PYTHONBIN@,${PYTHONBIN},g'

REPLACE_SH+=		plugins/asymptote/bin/tm_asy
REPLACE_SH+=		plugins/dratex/bin/tm_dratex
REPLACE_SH+=		plugins/eukleides/bin/tm_eukleides
REPLACE_SH+=		plugins/gnuplot/bin/tm_gnuplot
REPLACE_SH+=		plugins/lisp/bin/tm_lisp
REPLACE_SH+=		plugins/lush/bin/tm_lush
REPLACE_SH+=		plugins/matlab/bin/tm_matlab
REPLACE_SH+=		plugins/maxima/bin/maxima_detect
REPLACE_SH+=		plugins/maxima/bin/tm_maxima
REPLACE_SH+=		plugins/mupad/bin/tm_mupad_help
REPLACE_SH+=		plugins/octave/bin/tm_octave
REPLACE_SH+=		plugins/reduce/bin/tm_reduce
REPLACE_SH+=		plugins/texgraph/bin/tm_texgraph
REPLACE_SH+=		plugins/xypic/bin/tm_xypic

REPLACE_PERL+=		plugins/asymptote/bin/perl-tm_asy
REPLACE_PERL+=		plugins/asymptote/bin/tm_asy2

post-extract:
	${RM} -f ${WRKSRC}/plugins/eukleides/bin/tm_eukleides.old
	${RM} -f ${WRKSRC}/plugins/maxima/bin/maxima_filter

pre-install:
	${RM} -f ${WRKSRC}/TeXmacs/doc/devel/format/.log
	${FIND} ${WRKSRC}/plugins/ -name '*.orig' | ${XARGS} ${RM} -f

# just a helper script, not worth a full perl dependency
CHECK_INTERPRETER_SKIP=	libexec/TeXmacs/bin/bbox_add.pl
# but be friendly and set the path to something reasonable
REPLACE_INTERPRETER+=		optionalperl
REPLACE.optionalperl.old=	.*perl[^[:space:]]*
REPLACE.optionalperl.new=	${LOCALBASE}/bin/perl
REPLACE_FILES.optionalperl=	plugins/feynmf/bin/bbox_add.pl

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../lang/python/application.mk"
#.include "../../mk/tex.buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
