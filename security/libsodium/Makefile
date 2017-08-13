# $NetBSD: Makefile,v 1.10 2017/08/13 17:09:34 adam Exp $

DISTNAME=	libsodium-1.0.13
CATEGORIES=	security
MASTER_SITES=	https://download.libsodium.org/libsodium/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://download.libsodium.org/doc/
COMMENT=	Library for build higher-level cryptographic tools
LICENSE=	isc

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libsodium.pc.in

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
