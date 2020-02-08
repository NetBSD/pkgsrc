# $NetBSD: Makefile,v 1.2 2020/02/08 17:47:26 wiz Exp $

DISTNAME=	QR-Code-generator-1.4.0
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://dev-www.libreoffice.org/src/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/nayuki/QR-Code-generator
COMMENT=	High-quality QR Code generator in C/C++
LICENSE=	mit

USE_LANGUAGES=	c c++11
USE_TOOLS+=	gmake

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
	${INSTALL_PROGRAM} ${WRKSRC}/c/qrcodegen-worker ${DESTDIR}${PREFIX}/bin

	${INSTALL_LIB} ${WRKSRC}/cpp/libqrcodegen.a ${DESTDIR}${PREFIX}/lib/libqrcodegencpp.a
	${INSTALL_PROGRAM} ${WRKSRC}/cpp/QrCodeGeneratorDemo ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cpp/QrCodeGeneratorWorker ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cpp/*.hpp ${DESTDIR}${PREFIX}/include/qrcodegen

.include "../../mk/bsd.pkg.mk"
