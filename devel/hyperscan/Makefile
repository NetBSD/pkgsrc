# $NetBSD: Makefile,v 1.23 2024/12/29 14:56:38 adam Exp $

DISTNAME=	hyperscan-5.4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=intel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/intel/hyperscan
COMMENT=	High-performance regular expression matching library
LICENSE=	modified-bsd AND 2-clause-bsd AND boost-license

TOOL_DEPENDS+=	ragel-[0-9]*:../../devel/ragel

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
PYTHON_FOR_BUILD_ONLY=	yes

CMAKE_CONFIGURE_ARGS+=	-DBUILD_EXAMPLES=OFF
# Static libs are needed to build Chimera.
# Chimera is required for py-hyperscan.
CMAKE_CONFIGURE_ARGS+=	-DBUILD_STATIC_AND_SHARED=ON
PKGCONFIG_OVERRIDE+=	chimera/libch.pc.in
PKGCONFIG_OVERRIDE+=	libhs.pc.in

.include "../../mk/bsd.prefs.mk"

.if empty(CFLAGS:M-march*)
CFLAGS+=	-march=core2
.endif

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
