# $NetBSD: Makefile,v 1.22 2005/12/05 20:50:37 rillig Exp $
#

DISTNAME=	yacas-1.0.59
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

LDFLAGS+=	-Wl,-R${PREFIX}/lib/yacas

# dos2unix fix on a few files
pre-patch:
.for __tmp__ in src/cyacas.h src/cyacas.cpp plugins/pcre/pcre_config.h
	${MV} ${WRKSRC}/${__tmp__} ${WRKSRC}/${__tmp__}.bak
	${CAT} ${WRKSRC}/${__tmp__}.bak | ${TR} -d "\015" >  \
		${WRKSRC}/${__tmp__}
.endfor

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yacas.sh ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
.for __tmp__ in yacas.el yacas-names.el yacas-functions.el yacas-notebook.el \
	yacas-notebook.sty font-latex.el
	${INSTALL_DATA} ${WRKSRC}/YacasNotebook/${__tmp__} ${PREFIX}/share/emacs/site-lisp
.endfor

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
