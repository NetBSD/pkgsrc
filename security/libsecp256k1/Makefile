# $NetBSD: Makefile,v 1.1 2020/11/04 20:32:18 js Exp $

GITHUB_PROJECT=	secp256k1
GITHUB_TAG=	ac05f61fcf639a15b5101131561620303e4bd808
DISTNAME=	libsecp256k1-0.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=bitcoin-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bitcoin-core/secp256k1/
COMMENT=	Optimized C library for EC operations on curve secp256k1
LICENSE=	mit

WRKSRC=		${WRKDIR}/secp256k1-${GITHUB_TAG}
GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake gmake pkg-config
USE_LIBTOOL=	yes

# Inspired by the configure flags ArchLinux uses
CONFIGURE_ARGS+=	--disable-static
CONFIGURE_ARGS+=	--disable-benchmark
CONFIGURE_ARGS+=	--disable-coverage
CONFIGURE_ARGS+=	--enable-module-ecdh
CONFIGURE_ARGS+=	--enable-module-recovery

PKGCONFIG_OVERRIDE+=	libsecp256k1.pc.in

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../mk/bsd.pkg.mk"
