# $NetBSD: Makefile,v 1.8 2016/12/07 21:34:58 fhajny Exp $

DISTNAME=	lz4-1.7.4.2
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
