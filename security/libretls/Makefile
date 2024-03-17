# $NetBSD: Makefile,v 1.11 2024/03/17 00:35:34 nia Exp $

DISTNAME=		libretls-3.8.1
CATEGORIES=		security
MASTER_SITES=		https://causal.agency/libretls/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://git.causal.agency/libretls/about
COMMENT=		Port of libtls for OpenSSL
LICENSE=		isc

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

USE_FEATURES+=		strnlen

PKGCONFIG_OVERRIDE+=	libtls.pc.in

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
