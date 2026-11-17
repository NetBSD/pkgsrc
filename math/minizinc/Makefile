# $NetBSD: Makefile,v 1.3 2026/11/17 01:10:16 alnsn Exp $

PKGNAME=	minizinc-2.10.1
DISTNAME=	lib${PKGNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=MiniZinc/}
GITHUB_PROJECT=	libminizinc
GITHUB_TAG=	${PKGVERSION_NOREV}

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17
USE_TOOLS+=		flex bison

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

post-patch:
	${RM} -f ${WRKSRC}/include/minizinc/process.hh.orig

.include "../../math/gecode/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
