# $NetBSD: Makefile,v 1.12 2022/11/11 18:36:47 adam Exp $

DISTNAME=	spdlog-1.11.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gabime/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/gabime/spdlog
COMMENT=	Fast C++ logging library
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config
CMAKE_ARGS+=	-DSPDLOG_BUILD_SHARED=ON
CMAKE_ARGS+=	-DSPDLOG_FMT_EXTERNAL=ON

PKGCONFIG_OVERRIDE+=	cmake/spdlog.pc.in

LDFLAGS.SunOS+=		-lsocket

.include "../../lang/python/tool.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
