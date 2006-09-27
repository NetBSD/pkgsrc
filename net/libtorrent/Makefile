# $NetBSD: Makefile,v 1.15 2006/09/27 20:36:45 tron Exp $

DISTNAME=	libtorrent-0.10.2
CATEGORIES=	net
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://libtorrent.rakshasa.no/
COMMENT=	BitTorrent library written in C++ for *nix

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
GCC_REQD+=		3.3

.include "../../mk/compiler.mk"

# See http://libtorrent.rakshasa.no/ticket/96
.if !empty(CC_VERSION:Mgcc-4.*)
CXXFLAGS+=	-fpermissive -fno-strength-reduce -fno-thread-jumps \
		-fno-inline -fforce-addr
.endif

.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
