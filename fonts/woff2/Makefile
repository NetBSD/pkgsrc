# $NetBSD: Makefile,v 1.7 2025/08/11 08:27:08 wiz Exp $

DISTNAME=	woff2-1.0.2
PKGREVISION=	3
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/woff2/
COMMENT=	WOFF font file format library
LICENSE=	mit

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCANONICAL_PREFIXES=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

PKGCONFIG_OVERRIDE=		libwoff2common.pc
PKGCONFIG_OVERRIDE+=		libwoff2dec.pc
PKGCONFIG_OVERRIDE+=		libwoff2enc.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

pre-install:
	rm -f ${WRKSRC}/include/woff2/*.orig

.include "../../devel/cmake/build.mk"
.include "../../archivers/brotli/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
