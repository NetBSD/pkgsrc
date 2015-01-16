# $NetBSD: Makefile,v 1.7 2015/01/16 11:39:32 wiz Exp $

DISTNAME=	libsodium-1.0.1
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
