# $NetBSD: Makefile,v 1.20 2026/04/10 09:54:49 adam Exp $

DISTNAME=	libsodium-1.0.22
CATEGORIES=	security
MASTER_SITES=	https://download.libsodium.org/libsodium/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://doc.libsodium.org/
COMMENT=	Library for build higher-level cryptographic tools
LICENSE=	isc

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libsodium.pc.in
TEST_TARGET=		check

CTF_SUPPORTED=	no	# failed to get tag type: DW_DLE_DIE_NULL

.include "../../mk/bsd.pkg.mk"
