# $NetBSD: Makefile,v 1.109 2016/03/05 11:28:26 jperkin Exp $

DISTNAME=		TeXmacs-1.99.2-src
PKGNAME=		${DISTNAME:S/-src//}
PKGREVISION=		2
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.texmacs.org/pub/TeXmacs/tmftp/source/
MASTER_SITES+=		http://www.texmacs.org/Download/ftp/tmftp/source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.texmacs.org/
COMMENT=		GNU TeXmacs (free scientific text editor)

BUILD_TARGET=		TEXMACS

USE_TOOLS+=		gmake perl:run
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_RCC=${QTDIR}/bin/rcc
# XXX workaround for bug in configure
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--with-qt=${QTDIR}
#TEX_ACCEPTED=		teTeX3
BUILD_MAKE_FLAGS+=	QT_QTDIR=${QTDIR}

REPLACE_PYTHON=		plugins/python/bin/tm_python
REPLACE_PYTHON+=	plugins/sage/bin/tm_sage
REPLACE_PYTHON+=	plugins/mathematica/bin/realpath.py

SUBST_CLASSES+=		init
SUBST_STAGE.init=	post-patch
SUBST_FILES.init=	plugins/python/progs/init-python.scm
SUBST_SED.init=		-e 's,@PYTHONBIN@,${PYTHONBIN},g'

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
REPLACE_SH+=		plugins/mupad/bin/tm_mupad_help
REPLACE_SH+=		plugins/octave/bin/tm_octave
REPLACE_SH+=		plugins/reduce/bin/tm_reduce
REPLACE_SH+=		plugins/texgraph/bin/tm_texgraph
REPLACE_SH+=		plugins/xypic/bin/tm_xypic

REPLACE_PERL+=		plugins/asymptote/bin/perl-tm_asy
REPLACE_PERL+=		plugins/asymptote/bin/tm_asy2

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

DEPENDS+=	ps2pkm>=1.5:../../fonts/ps2pkm

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../lang/python/application.mk"
#.include "../../mk/tex.buildlink3.mk"
.include "../../print/ghostscript/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
