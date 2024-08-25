# $NetBSD: Makefile,v 1.8 2024/08/25 06:18:59 wiz Exp $

DISTNAME=	double-conversion-3.3.0
CATEGORIES=	math converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/double-conversion/
COMMENT=	Conversion routines for IEEE doubles
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
