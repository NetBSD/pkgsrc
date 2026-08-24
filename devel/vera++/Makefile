# $NetBSD: Makefile,v 1.44 2026/08/24 08:42:16 adam Exp $

DISTNAME=	vera++-1.3.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=verateam/}
GITHUB_PROJECT=	vera
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/verateam/vera
COMMENT=	Programmable verification and analysis tool for C++
LICENSE=	boost-license

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++

# Required luabind
CMAKE_CONFIGURE_ARGS+=	-DVERA_LUA=OFF
# Not compatible with latest Python
CMAKE_CONFIGURE_ARGS+=	-DVERA_PYTHON=OFF
CMAKE_CONFIGURE_ARGS+=	-DVERA_USE_SYSTEM_BOOST=ON
CMAKE_CONFIGURE_ARGS+=	-DVERA_USE_SYSTEM_LUA=ON
CMAKE_CONFIGURE_ARGS+=	-DVERA_USE_SYSTEM_PYTHON=ON

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/py-boost/buildlink3.mk"
#.include "../../lang/lua/buildlink3.mk"
#.include "../../lang/python/pyversion.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
