# $NetBSD: Makefile,v 1.5 2024/08/25 06:18:42 wiz Exp $

DISTNAME=	woff2-1.0.2
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/woff2/
COMMENT=	WOFF font file format library
LICENSE=	mit

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCANONICAL_PREFIXES=ON

PKGCONFIG_OVERRIDE=		libwoff2common.pc
PKGCONFIG_OVERRIDE+=		libwoff2dec.pc
PKGCONFIG_OVERRIDE+=		libwoff2enc.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../devel/cmake/build.mk"
.include "../../archivers/brotli/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
