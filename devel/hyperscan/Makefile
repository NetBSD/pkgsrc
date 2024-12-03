# $NetBSD: Makefile,v 1.22 2024/12/03 19:57:51 minskim Exp $

DISTNAME=	hyperscan-5.0.0
PKGREVISION=	12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=intel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/intel/hyperscan
COMMENT=	High-performance regular expression matching library
LICENSE=	modified-bsd AND 2-clause-bsd AND boost-license

TOOL_DEPENDS+=	ragel-[0-9]*:../../devel/ragel

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

USE_CMAKE=		yes
USE_LANGUAGES=		c99 c++
USE_CXX_FEATURES+=	c++11
USE_TOOLS+=		pkg-config
PYTHON_FOR_BUILD_ONLY=	yes

CMAKE_CONFIGURE_ARGS+=		-DBUILD_SHARED_LIBS=ON
PKGCONFIG_OVERRIDE+=	libhs.pc.in

.include "../../mk/bsd.prefs.mk"

.if empty(CFLAGS:M-march*)
CFLAGS+=	-march=core2
.endif

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
