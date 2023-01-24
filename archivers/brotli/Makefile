# $NetBSD: Makefile,v 1.10 2023/01/24 18:36:17 wiz Exp $

DISTNAME=	brotli-1.0.9
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

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
