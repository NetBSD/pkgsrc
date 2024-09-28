# $NetBSD: Makefile,v 1.6 2024/09/28 08:27:55 wiz Exp $

DISTNAME=	QR-Code-generator-1.8.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=nayuki/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/nayuki/QR-Code-generator
COMMENT=	High-quality QR Code generator in C/C++
LICENSE=	mit

USE_LANGUAGES=	c c++

USE_CC_FEATURES+=	c99
USE_CXX_FEATURES+=	c++11

USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/${DISTNAME}

BUILDLINK_TRANSFORM+=	rm:-fsanitize=undefined
# Automatically added to CXXFLAGS too.
CFLAGS+=		-fPIC

BUILD_DIRS=	c cpp

INSTALLATION_DIRS+=	bin include/qrcodegen lib

do-install:
	${INSTALL_LIB} ${WRKSRC}/c/libqrcodegen.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/c/*.h ${DESTDIR}${PREFIX}/include/qrcodegen
	${INSTALL_PROGRAM} ${WRKSRC}/c/qrcodegen-demo ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/c/qrcodegen-test ${DESTDIR}${PREFIX}/bin

	${INSTALL_LIB} ${WRKSRC}/cpp/libqrcodegencpp.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/cpp/QrCodeGeneratorDemo ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cpp/*.hpp ${DESTDIR}${PREFIX}/include/qrcodegen

.include "../../mk/bsd.pkg.mk"
