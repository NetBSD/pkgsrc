# $NetBSD: Makefile,v 1.17 2025/07/08 21:16:00 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=		s6-dns-2.4.1.0
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=skarnet/}
GITHUB_PROJECT=		s6-dns
GITHUB_TAG=		448e2c2668e87726b9e4428acc230d12e80d5049

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.skarnet.org/software/s6-dns/
COMMENT=		Suite of DNS client programs and libraries
LICENSE=		isc

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--enable-pkgconfig
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--disable-allstatic

.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
