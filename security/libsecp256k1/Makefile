# $NetBSD: Makefile,v 1.3 2025/05/17 10:03:18 nia Exp $

DISTNAME=	libsecp256k1-0.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=bitcoin-core/}
GITHUB_PROJECT=	secp256k1
GITHUB_TAG=	ac05f61fcf639a15b5101131561620303e4bd808

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

SECP256K1_BIG_ENDIAN?=	no

.include "../../mk/bsd.prefs.mk"

.for plat in ${BIGENDIANPLATFORMS}
.  if !empty(MACHINE_PLATFORM:M${plat})
SECP256K1_BIG_ENDIAN=	yes
.  endif
.endfor

.if ${SECP256K1_BIG_ENDIAN:tl} == "no"
CPPFLAGS+=	-DSECP256K1_LITTLE_ENDIAN=1
.else
CPPFLAGS+=	-DSECP256K1_BIG_ENDIAN=1
.endif

CONFIGURE_ENV+=		CC_FOR_BUILD=${CC:Q}
CONFIGURE_ENV+=		CFLAGS_FOR_BUILD=${CFLAGS:Q}
CONFIGURE_ENV+=		CPPFLAGS_FOR_BUILD=${CPPFLAGS:Q}
CONFIGURE_ENV+=		LDFLAGS_FOR_BUILD=${LDFLAGS:Q}

PKGCONFIG_OVERRIDE+=	libsecp256k1.pc.in

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../mk/bsd.pkg.mk"
