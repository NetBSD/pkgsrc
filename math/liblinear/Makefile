# $NetBSD: Makefile,v 1.1.1.1 2014/10/19 09:57:21 cheusov Exp $

DISTNAME=	liblinear-1.94
CATEGORIES=	math
MASTER_SITES=	http://www.csie.ntu.edu.tw/~cjlin/liblinear/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.csie.ntu.edu.tw/~cjlin/liblinear/
COMMENT=	Library for large linear classification
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

BUILD_TARGET=	all lib
AUTO_MKDIRS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/predict ${DESTDIR}${PREFIX}/bin/liblinear-predict
	${INSTALL_PROGRAM} ${WRKSRC}/train ${DESTDIR}${PREFIX}/bin/liblinear-train
	${INSTALL_LIB} ${WRKSRC}/liblinear.so.1 ${DESTDIR}${PREFIX}/lib
	${LN} -s liblinear.so.1 ${DESTDIR}${PREFIX}/lib/liblinear.so
	${INSTALL_DATA} ${WRKSRC}/linear.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/heart_scale \
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
