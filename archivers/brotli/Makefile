# $NetBSD: Makefile,v 1.12 2023/11/22 18:32:47 schmonz Exp $

DISTNAME=	brotli-1.1.0
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
# distfile is distinct from py-brotli's but filename differs only by case
DIST_SUBDIR=	brotli

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/brotli
COMMENT=	Generic-purpose lossless compression algorithm
LICENSE=	mit

USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	scripts/libbrotlicommon.pc.in
PKGCONFIG_OVERRIDE+=	scripts/libbrotlidec.pc.in
PKGCONFIG_OVERRIDE+=	scripts/libbrotlienc.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
