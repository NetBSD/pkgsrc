# $NetBSD: Makefile,v 1.75 2008/04/21 20:04:43 drochner Exp $

DISTNAME=		TeXmacs-1.0.6.14-src
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.texmacs.org/pub/TeXmacs/targz/
MASTER_SITES+=		http://www.texmacs.org/Download/ftp/targz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.texmacs.org/
COMMENT=		GNU TeXmacs (free scientific text editor)

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		TEXMACS

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
TEX_ACCEPTED=		teTeX3

PYTHON_PATCH_SCRIPTS=	plugins/python/bin/tm_python

SUBST_CLASSES+=		init
SUBST_STAGE.init=	post-patch
SUBST_FILES.init=	plugins/python/progs/init-python.scm
SUBST_SED.init=		-e 's,@PYTHONBIN@,${PYTHONBIN},g'

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
REPLACE_SH+=		plugins/xypic/bin/tm_xypic

pre-install:
	${RM} -f ${WRKSRC}/TeXmacs/doc/devel/format/.log
	${FIND} ${WRKSRC}/plugins/ -name '*.orig' | ${XARGS} ${RM}

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
