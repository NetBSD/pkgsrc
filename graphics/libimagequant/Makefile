# $NetBSD: Makefile,v 1.3 2017/06/19 20:14:45 adam Exp $

DISTNAME=	libimagequant-2.9.1
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
CONFIGURE_ARGS+=	--prefix="${PREFIX}"
CONFIGURE_ARGS+=	--without-openmp
BUILD_TARGET=		shared

INSTALLATION_DIRS=	include lib
REPLACE_SH=		configure

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
