# $NetBSD: Makefile,v 1.2 2018/05/15 11:46:43 jperkin Exp $

DISTNAME=	woff2-1.0.2
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/woff2/
COMMENT=	WOFF font file format library
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCANONICAL_PREFIXES=ON

PKGCONFIG_OVERRIDE=		libwoff2common.pc
PKGCONFIG_OVERRIDE+=		libwoff2dec.pc
PKGCONFIG_OVERRIDE+=		libwoff2enc.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../archivers/brotli/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
