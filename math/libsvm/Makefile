# $NetBSD: Makefile,v 1.1 2014/04/02 07:31:43 rodent Exp $
#

DISTNAME=	libsvm-3.18
CATEGORIES=	math
MASTER_SITES=	http://www.csie.ntu.edu.tw/~cjlin/libsvm/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.csie.ntu.edu.tw/~cjlin/libsvm/
COMMENT=	Library for Support Vector Machines
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

BUILD_TARGET=	all lib
INSTALLATION_DIRS+=	bin lib share/doc/${PKGBASE} share/examples/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/svm-predict ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/svm-scale ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/svm-train ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libsvm.so.2 ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/FAQ.html \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/heart_scale \
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
