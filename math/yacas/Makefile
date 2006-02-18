# $NetBSD: Makefile,v 1.24 2006/02/18 13:47:55 rillig Exp $
#

DISTNAME=	yacas-1.0.59
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://yacas.sourceforge.net/backups/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://yacas.sourceforge.net/
COMMENT=	Yet Another Computer Algebra System

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake perl
USE_LIBTOOL=	YES

TEST_TARGET=	test

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/yacas

SUBST_CLASSES+=		d2u
SUBST_STAGE.d2u=	pre-patch
SUBST_FILES.d2u=	src/cyacas.h src/cyacas.cpp plugins/pcre/pcre_config.h
SUBST_FILTER_CMD.d2u=	${TR} -d '\015'

post-install:
	${INSTALL_SCRIPT} ${WRKSRC:Q}/yacas.sh ${PREFIX:Q}/bin
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/emacs/site-lisp
.for f in yacas.el yacas-names.el yacas-functions.el yacas-notebook.el \
	yacas-notebook.sty font-latex.el
	${INSTALL_DATA} ${WRKSRC:Q}/YacasNotebook/${f:Q} ${PREFIX:Q}/share/emacs/site-lisp/
.endfor

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
