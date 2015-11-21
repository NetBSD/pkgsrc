# $NetBSD: Makefile,v 1.8 2015/11/21 09:21:40 wiz Exp $

DISTNAME=	libsodium-1.0.6
CATEGORIES=	security
MASTER_SITES=	https://download.libsodium.org/libsodium/releases/

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	https://download.libsodium.org/doc/
COMMENT=	Library for build higher-level cryptographic tools
LICENSE=	isc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

TEST_TARGET=	check

PKGCONFIG_OVERRIDE=	libsodium.pc.in

.include "../../mk/bsd.pkg.mk"
