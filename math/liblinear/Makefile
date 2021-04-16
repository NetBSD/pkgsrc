# $NetBSD: Makefile,v 1.8 2021/04/16 06:48:04 adam Exp $

DISTNAME=	liblinear-2.43
CATEGORIES=	math
MASTER_SITES=	https://www.csie.ntu.edu.tw/~cjlin/liblinear/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://www.csie.ntu.edu.tw/~cjlin/liblinear/
COMMENT=	Library for large linear classification
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

BUILD_TARGET=	all lib

MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS+=	bin include lib share/doc/${PKGBASE} share/examples/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/predict ${DESTDIR}${PREFIX}/bin/liblinear-predict
	${INSTALL_PROGRAM} ${WRKSRC}/train ${DESTDIR}${PREFIX}/bin/liblinear-train
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/liblinear.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/linear.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/heart_scale \
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
