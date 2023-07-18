# $NetBSD: Makefile,v 1.17 2023/07/18 04:59:01 adam Exp $

DISTNAME=	spdlog-1.12.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gabime/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/gabime/spdlog
COMMENT=	Fast C++ logging library
LICENSE=	mit

USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config
CMAKE_ARGS+=	-DSPDLOG_BUILD_SHARED=ON
CMAKE_ARGS+=	-DSPDLOG_FMT_EXTERNAL=ON

PKGCONFIG_OVERRIDE+=	cmake/spdlog.pc.in

LDFLAGS.SunOS+=		-lsocket

post-install:
	${FIND} ${DESTDIR} -name '*.orig' -exec rm -f '{}' ';'

.include "../../devel/cmake/build.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
