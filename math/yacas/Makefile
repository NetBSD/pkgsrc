# $NetBSD: Makefile,v 1.6 2001/05/05 23:54:47 jtb Exp $
#

DISTNAME=	yacas-latest
PKGNAME=	yacas-1.0.43
CATEGORIES=	math
MASTER_SITES=	http://www.xs4all.nl/~apinkus/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.xs4all.nl/~apinkus/yacas.html
COMMENT=	Yet Another Computer Algebra System

DIST_SUBDIR=	${PKGNAME}
WRKSRC=		${WRKDIR}/${PKGNAME}

GNU_CONFIGURE=	YES

post-patch:
	cd ${WRKSRC}; ${SED} 's|@prefix@|${PREFIX}|g' yacas.sh.in > \
	  yacas.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yacas.sh ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/yacas.el ${PREFIX}/share/emacs/site-lisp

.include "../../mk/bsd.pkg.mk"
