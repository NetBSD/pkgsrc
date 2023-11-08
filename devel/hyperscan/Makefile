# $NetBSD: Makefile,v 1.15 2023/11/08 13:18:48 wiz Exp $

DISTNAME=	hyperscan-5.0.0
PKGREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=01org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://01.org/hyperscan
COMMENT=	High-performance regular expression matching library
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

TOOL_DEPENDS+=	ragel-[0-9]*:../../devel/ragel

PYTHON_FOR_BUILD_ONLY=	yes
USE_CMAKE=		yes
USE_LANGUAGES=		c99 c++
USE_CXX_FEATURES+=	c++11
USE_TOOLS+=		pkg-config

CMAKE_ARGS+=		-DBUILD_SHARED_LIBS=ON
PKGCONFIG_OVERRIDE+=	libhs.pc.in

.include "../../mk/bsd.prefs.mk"

.if empty(CFLAGS:M-march*)
CFLAGS+=	-march=core2
.endif

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
