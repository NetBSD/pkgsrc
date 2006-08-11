# $NetBSD: Makefile,v 1.61 2006/08/11 18:05:12 drochner Exp $

DISTNAME=		TeXmacs-1.0.6.5-src
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.texmacs.org/pub/TeXmacs/targz/
MASTER_SITES+=		http://www.texmacs.org/Download/ftp/targz/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.texmacs.org/
COMMENT=		GNU TeXmacs (free scientific text editor)

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

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash+=	plugins/dratex/bin/tm_dratex
REPLACE_FILES.bash+=	plugins/eukleides/bin/tm_eukleides
REPLACE_FILES.bash+=	plugins/gnuplot/bin/tm_gnuplot
REPLACE_FILES.bash+=	plugins/lisp/bin/tm_lisp
REPLACE_FILES.bash+=	plugins/lush/bin/tm_lush
REPLACE_FILES.bash+=	plugins/matlab/bin/tm_matlab
REPLACE_FILES.bash+=	plugins/maxima/bin/maxima_detect
REPLACE_FILES.bash+=	plugins/maxima/bin/tm_maxima
REPLACE_FILES.bash+=	plugins/mupad/bin/tm_mupad_help
REPLACE_FILES.bash+=	plugins/octave/bin/tm_octave
REPLACE_FILES.bash+=	plugins/reduce/bin/tm_reduce
REPLACE_FILES.bash+=	plugins/xypic/bin/tm_xypic

pre-install:
	${RM} -f ${WRKSRC}/TeXmacs/doc/devel/format/.log
	${FIND} ${WRKSRC}/plugins/ -name '*.orig' | ${XARGS} ${RM}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/tex.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
