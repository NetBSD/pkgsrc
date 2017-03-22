# $NetBSD: Makefile,v 1.2 2017/03/22 02:13:05 adam Exp $

DISTNAME=	libimagequant-2.9.0
CATEGORIES=	graphics
MASTER_SITES+=	${MASTER_SITE_GITHUB:=ImageOptim/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://pngquant.org/lib/
COMMENT=	High-quality conversion of RGBA images to 8-bit indexed-color
LICENSE=	gnu-gpl-v3

GITHUB_TAG=	${PKGVERSION_NOREV}

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-sse
CONFIGURE_ARGS+=	--prefix="${PREFIX}"
CONFIGURE_ARGS+=	--without-openmp
BUILD_TARGET=		shared

INSTALLATION_DIRS=	include lib
REPLACE_SH=		configure

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64"
CONFIGURE_ARGS+=	--enable-sse
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/libimagequant.h ${DESTDIR}${PREFIX}/include/libimagequant.h
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libimagequant.la ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
