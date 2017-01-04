# $NetBSD: Makefile,v 1.9 2017/01/04 15:43:51 fhajny Exp $

DISTNAME=	lz4-1.7.5
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=lz4/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://lz4.github.io/lz4/
COMMENT=	Extremely Fast Compression algorithm
LICENSE=	2-clause-bsd

GITHUB_TAG=	v${PKGVERSION_NOREV}

USE_LANGUAGES=	c c99
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	lib/liblz4.pc.in

.include "../../mk/bsd.pkg.mk"
