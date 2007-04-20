# $NetBSD: Makefile,v 1.20 2007/04/20 13:37:57 tron Exp $

DISTNAME=	libtorrent-0.11.4
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE:=downloads/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://libtorrent.rakshasa.no/
COMMENT=	BitTorrent library written in C++ for *nix

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug
GCC_REQD+=		3.3

.include "../../mk/compiler.mk"

# See http://libtorrent.rakshasa.no/ticket/96
.if !empty(CC_VERSION:Mgcc-4.*)
CXXFLAGS+=	-fpermissive -fno-strength-reduce -fno-thread-jumps \
		-fno-inline -fforce-addr
.endif

.include "../../security/openssl/buildlink3.mk"
.if !exists(${BUILDLINK_PREFIX.openssl}/lib/pkgconfig/openssl.pc)
OPENSSL_CFLAGS=	-I${BUILDLINK_PREFIX.openssl}/include
OPENSSL_LIBS=	-L${BUILDLINK_PREFIX.openssl}/lib \
		-W,-lR${BUILDLINK_PREFIX.openssl}/lib

CONFIGURE_ENV+=	OPENSSL_CFLAGS=${OPENSSL_CFLAGS:Q}
CONFIGURE_ENV+=	OPENSSL_LIBS=${OPENSSL_LIBS:Q}
.endif

.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
