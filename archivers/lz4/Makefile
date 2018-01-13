# $NetBSD: Makefile,v 1.11 2018/01/13 19:00:09 adam Exp $

DISTNAME=	lz4-1.8.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=lz4/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://lz4.github.io/lz4/
COMMENT=	Extremely Fast Compression algorithm
LICENSE=	2-clause-bsd

GITHUB_TAG=	v${PKGVERSION_NOREV}

USE_LANGUAGES=		c99 c++
USE_TOOLS+=		gmake pkg-config

PKGCONFIG_OVERRIDE+=	lib/liblz4.pc.in

TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
