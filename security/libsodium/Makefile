# $NetBSD: Makefile,v 1.16 2023/09/18 12:38:21 adam Exp $

DISTNAME=	libsodium-1.0.19
CATEGORIES=	security
MASTER_SITES=	https://download.libsodium.org/libsodium/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://download.libsodium.org/doc/
COMMENT=	Library for build higher-level cryptographic tools
LICENSE=	isc

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libsodium.pc.in

WRKSRC=		${WRKDIR}/libsodium-stable
TEST_TARGET=	check

CTF_SUPPORTED=	no	# failed to get tag type: DW_DLE_DIE_NULL

.include "../../mk/bsd.pkg.mk"
