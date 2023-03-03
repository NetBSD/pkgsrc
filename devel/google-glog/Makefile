# $NetBSD: Makefile,v 1.11 2023/03/03 09:59:58 adam Exp $

DISTNAME=	glog-0.6.0
PKGNAME=	google-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=	glog
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/glog
COMMENT=	Application Level Logging library for C++
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DWITH_UNWIND=OFF

BUILDLINK_TRANSFORM.SunOS+=	rm:-pie

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && exists(/usr/include/execinfo.h)
LDFLAGS+=	-lexecinfo
.endif

.include "../../devel/cmake/build.mk"
.include "../../devel/gflags/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
