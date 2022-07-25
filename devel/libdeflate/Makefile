# $NetBSD: Makefile,v 1.2 2022/07/25 11:12:22 wiz Exp $

DISTNAME=	libdeflate-1.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ebiggers/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/ebiggers/libdeflate/
COMMENT=	Optimized deflate/zlib/gzip library
LICENSE=	mit

USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	libdeflate.pc.in

.include "../../mk/bsd.pkg.mk"
