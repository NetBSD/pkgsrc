# $NetBSD: Makefile,v 1.3 2025/08/20 11:34:58 wiz Exp $

DISTNAME=	laszip-src-3.4.3
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=LASzip/}
GITHUB_PROJECT=	LASzip
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://laszip.org/
COMMENT=	Free and lossless LiDAR compression
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=  -DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
