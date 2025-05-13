# $NetBSD: Makefile,v 1.16 2025/05/13 03:49:58 schmonz Exp $

DISTNAME=		s6-dns-2.4.1.0
CATEGORIES=		net
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.skarnet.org/software/s6-dns/
COMMENT=		Suite of DNS client programs and libraries
LICENSE=		isc

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--enable-pkgconfig

.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
