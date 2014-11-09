# $NetBSD: Makefile,v 1.52.4.1 2014/11/09 15:50:27 spz Exp $

DISTNAME=	libtorrent-0.13.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

OWNER=		tron@NetBSD.org
HOMEPAGE=	http://rakshasa.github.io/rtorrent/
COMMENT=	BitTorrent library written in C++ for *nix
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug
LDFLAGS+=		-lz

.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == "alpha" || \
    ${MACHINE_ARCH} == "i386" || \
    ${MACHINE_ARCH} == "powerpc" || \
    ${MACHINE_ARCH} == "x86_64"
GCC_REQD+=		4.1.3
.else
GCC_REQD+=		4.2.1
.endif

# configure check is fooled by trap & emulate of unaligned access on alpha
.if (${MACHINE_ARCH} == "alpha")
CONFIGURE_ARGS+= --enable-aligned
.endif

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--with-kqueue
.endif

.include "../../mk/compiler.mk"

# See http://libtorrent.rakshasa.no/ticket/96
.if !empty(CC_VERSION:Mgcc-4.*)
CXXFLAGS+=	-fpermissive -fno-strength-reduce -fno-thread-jumps \
		-fno-inline -fforce-addr
.endif

.if empty(MACHINE_ARCH:M*64*) && ${MACHINE_ARCH} != "alpha"
CONFIGURE_ARGS+=	--disable-instrumentation
.endif

.include "../../security/openssl/buildlink3.mk"
.if !exists(${BUILDLINK_PREFIX.openssl}/lib/pkgconfig/openssl.pc)
OPENSSL_CFLAGS=	-I${BUILDLINK_PREFIX.openssl}/include
OPENSSL_LIBS=	-L${BUILDLINK_PREFIX.openssl}/lib \
		-W,-lR${BUILDLINK_PREFIX.openssl}/lib

CONFIGURE_ENV+=	OPENSSL_CFLAGS=${OPENSSL_CFLAGS:Q}
CONFIGURE_ENV+=	OPENSSL_LIBS=${OPENSSL_LIBS:Q}
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-std=c++11
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
