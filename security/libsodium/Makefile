# $NetBSD: Makefile,v 1.9 2016/02/07 10:59:18 adam Exp $

DISTNAME=	libsodium-1.0.8
CATEGORIES=	security
MASTER_SITES=	https://download.libsodium.org/libsodium/releases/

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	https://download.libsodium.org/doc/
COMMENT=	Library for build higher-level cryptographic tools
LICENSE=	isc

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libsodium.pc.in

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
