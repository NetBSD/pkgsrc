# $NetBSD: Makefile,v 1.20 2021/01/21 19:58:47 adam Exp $

DISTNAME=	libimagequant-2.13.1
CATEGORIES=	graphics
MASTER_SITES+=	${MASTER_SITE_GITHUB:=ImageOptim/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://pngquant.org/lib/
COMMENT=	High-quality conversion of RGBA images to 8-bit indexed-color
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=		yes
USE_TOOLS+=		bash gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix="${PREFIX}"
BUILD_TARGET=		shared

CONFIG_SHELL=		${BASH}
INSTALLATION_DIRS=	include lib
REPLACE_BASH=		configure

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64"
CONFIGURE_ARGS+=	--enable-sse
.else
CONFIGURE_ARGS+=	--disable-sse
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/libimagequant.h ${DESTDIR}${PREFIX}/include/libimagequant.h
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libimagequant.la ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
