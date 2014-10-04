# $NetBSD: Makefile,v 1.6 2014/10/04 12:59:02 wiz Exp $

DISTNAME=	libsodium-1.0.0
CATEGORIES=	security
MASTER_SITES=	http://download.libsodium.org/libsodium/releases/

MAINTAINER=	csosstudy@gmail.com
HOMEPAGE=	https://github.com/jedisct1/libsodium
COMMENT=	Library for build higher-level cryptographic tools
LICENSE=	isc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

TEST_TARGET=	check

PKGCONFIG_OVERRIDE=	libsodium.pc.in

.include "../../mk/bsd.pkg.mk"
