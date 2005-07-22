# $NetBSD: Makefile,v 1.1.1.1 2005/07/22 22:24:39 adam Exp $

DISTNAME=	libtorrent-0.7.0
CATEGORIES=	net
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://libtorrent.rakshasa.no/
COMMENT=	BitTorrent library written in C++ for *nix

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
