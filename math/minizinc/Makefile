# $NetBSD: Makefile,v 1.1 2026/10/10 14:31:03 alnsn Exp $

PKGNAME=	minizinc-2.9.7
DISTNAME=	lib${PKGNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=MiniZinc/}
GITHUB_TAG=	${PKGVERSION_NOREV}

USE_LANGUAGES=	c c++
USE_TOOLS+=	flex bison

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MiniZinc/libminizinc/
COMMENT=	High-level constraint modelling language
LICENSE=	mpl-2.0

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DMZN_STATIC_STDLIB_DIR=${PREFIX}/share/minizinc
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_chuffed=TRUE

# Chuffed is disabled at build time but it's discoverable at runtime:
DEPENDS+=	chuffed>=0.14.0:../../math/chuffed

WRKSRC=		${WRKDIR}/${DISTNAME}

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
