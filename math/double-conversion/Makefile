# $NetBSD: Makefile,v 1.1 2019/06/02 14:15:45 mef Exp $

DISTNAME=	double-conversion-3.1.5
CATEGORIES=	math converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_PROJECT=	double-conversion
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/double-conversion/
COMMENT=	Conversion routines for IEEE doubles
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARGS+=	-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON

.include "../../mk/bsd.pkg.mk"
