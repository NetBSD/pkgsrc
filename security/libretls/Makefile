# $NetBSD: Makefile,v 1.5 2021/10/18 14:33:04 schmonz Exp $

DISTNAME=		libretls-3.4.1
CATEGORIES=		security
MASTER_SITES=		https://causal.agency/libretls/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://git.causal.agency/libretls/about
COMMENT=		Port of libtls for OpenSSL
LICENSE=		isc

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	libtls.pc.in

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
