# $NetBSD: Makefile,v 1.10 2022/04/24 19:53:22 tnn Exp $

DISTNAME=		spdlog-1.10.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=gabime/}
GITHUB_PROJECT=		spdlog
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://github.com/gabime/spdlog
COMMENT=		Fast C++ logging library
LICENSE=		mit

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
USE_CMAKE=		yes
CMAKE_ARGS+=		-DSPDLOG_BUILD_SHARED=ON

PKGCONFIG_OVERRIDE+=	cmake/spdlog.pc.in

LDFLAGS.SunOS+=		-lsocket

# This doesn't work due to mk/plist bug. See tech-pkg@
#PLIST_VARS+=		dylib notdylib
#PLIST.dylib.Darwin=	yes
#PLIST.dylib.Darwin=
#PLIST.nodylib.Darwin=
#PLIST.notdylib.*=	yes

OPSYSVARS+=		SOEXT DYLIB NOTDYLIB
PLIST_SUBST+=		SOEXT=${SOEXT} PLIST.dylib=${DYLIB} PLIST.notdylib=${NOTDYLIB}
SOEXT.Darwin=		dylib
SOEXT.*=		so
DYLIB.Darwin=
DYLIB.*=		@comment
NOTDYLIB.Darwin=	@comment
NOTDYLIB.*=

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
