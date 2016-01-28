# $NetBSD: Makefile,v 1.3 2016/01/28 11:34:48 jperkin Exp $

DISTNAME=	liblinear-2.1
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.csie.ntu.edu.tw/~cjlin/liblinear/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.csie.ntu.edu.tw/~cjlin/liblinear/
COMMENT=	Library for large linear classification
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

BUILD_TARGET=	all lib
AUTO_MKDIRS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/predict ${DESTDIR}${PREFIX}/bin/liblinear-predict
	${INSTALL_PROGRAM} ${WRKSRC}/train ${DESTDIR}${PREFIX}/bin/liblinear-train
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/liblinear.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/linear.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/heart_scale \
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
