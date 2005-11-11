# $NetBSD: Makefile,v 1.50 2005/11/11 18:50:24 tonio Exp $

DISTNAME=	TeXmacs-1.0.5.12-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/targz/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.texmacs.org/
COMMENT=	GNU TeXmacs (free scientific text editor)

BUILD_TARGET=	TEXMACS

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
TEX_ACCEPTED=		teTeX1 teTeX2 teTeX3

PYTHON_PATCH_SCRIPTS=	plugins/python/bin/tm_python

SUBST_CLASSES+=		init
SUBST_STAGE.init=	post-patch
SUBST_FILES.init=	plugins/python/progs/init-python.scm
SUBST_SED.init=		-e 's,@PYTHONBIN@,${PYTHONBIN},g'

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	post-patch
SUBST_FILES.bash+=	plugins/dratex/bin/tm_dratex
SUBST_FILES.bash+=	plugins/eukleides/bin/tm_eukleides
SUBST_FILES.bash+=	plugins/gnuplot/bin/tm_gnuplot
SUBST_FILES.bash+=	plugins/lisp/bin/tm_lisp
SUBST_FILES.bash+=	plugins/lush/bin/tm_lush
SUBST_FILES.bash+=	plugins/matlab/bin/tm_matlab
SUBST_FILES.bash+=	plugins/maxima/bin/maxima_detect
SUBST_FILES.bash+=	plugins/maxima/bin/tm_maxima
SUBST_FILES.bash+=	plugins/mupad/bin/tm_mupad_help
SUBST_FILES.bash+=	plugins/octave/bin/tm_octave
SUBST_FILES.bash+=	plugins/reduce/bin/tm_reduce
SUBST_FILES.bash+=	plugins/xypic/bin/tm_xypic
SUBST_SED.bash=		-e 's,^\#!/bin/bash,\#!/bin/sh,'

pre-install:
	${FIND} ${WRKSRC}/plugins/ . -name '*.orig' | xargs ${RM}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/tex.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
