# $NetBSD: Makefile,v 1.11 2017/10/12 12:08:39 adam Exp $

DISTNAME=	libsodium-1.0.15
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
