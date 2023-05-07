# $NetBSD: Makefile,v 1.7 2023/05/07 12:28:42 wiz Exp $

DISTNAME=	imath-3.1.7
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=AcademySoftwareFoundation/}
GITHUB_PROJECT=	Imath
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openexr.com/
COMMENT=	2D and 3D vector, matrix, and math operations for computer graphics
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++14
PTHREAD_OPTS=	require

# C++14
GCC_REQD+=	6

PKGCONFIG_OVERRIDE=	config/Imath.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
