# $NetBSD: Makefile,v 1.15 2025/08/20 19:25:54 wiz Exp $

DISTNAME=	imath-3.2.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=AcademySoftwareFoundation/}
GITHUB_PROJECT=	Imath
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openexr.com/
COMMENT=	2D and 3D vector, matrix, and math operations for computer graphics
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
PTHREAD_OPTS=	require

USE_CXX_FEATURES+=	c++14

PKGCONFIG_OVERRIDE=	config/Imath.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
