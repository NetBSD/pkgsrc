# $NetBSD: Makefile,v 1.1 2023/07/21 15:54:20 hauke Exp $

DISTNAME=	libimagequant-2.18.0
CATEGORIES=	graphics
MASTER_SITES+=	${MASTER_SITE_GITHUB:=ImageOptim/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkg-users@NetBSD.org
HOMEPAGE=	https://pngquant.org/lib/
COMMENT=	Conversion of RGBA images to 8-bit indexed-color (2.x, C-only)
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
	${INSTALL_DATA} ${WRKSRC}/libimagequant.h \
		${DESTDIR}${PREFIX}/include/libimagequant.h
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/libimagequant.la ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
