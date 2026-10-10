# $NetBSD: Makefile,v 1.1 2026/10/10 00:36:41 alnsn Exp $

DISTNAME=	chuffed-0.14.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=chuffed/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chuffed/chuffed
COMMENT=	The Chuffed CP solver
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	bison flex

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCP_PROFILER=OFF

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
