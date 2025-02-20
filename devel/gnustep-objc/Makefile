# $NetBSD: Makefile,v 1.42 2025/02/20 14:34:01 wiz Exp $

DISTNAME=	libobjc2-2.2.1
PKGNAME=	${DISTNAME:S/libobjc2/gnustep-objc/}
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GITHUB:=gnustep/}
GITHUB_PROJECT=	libobjc2
GITHUB_TAG=	v2.2.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gnustep/libobjc2
COMMENT=	Objective-C runtime
LICENSE=	mit

TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang

USE_LANGUAGES=			objc c++
USE_TOOLS+=			pax
USE_CXX_FEATURES+=		c++11

CMAKE_CONFIGURE_ARGS+=		-Wno-dev

INSTALLATION_DIRS=		lib include/objc

post-extract:
	cd ${BUILDLINK_PREFIX.robin-map} && \
 	    pax -rwpam include/tsl ${WRKSRC}/third_party/robin-map/

.include "../../mk/compiler.mk"

.include "../../mk/bsd.prefs.mk"

# Building tests with GCC is not supported.
.if !${CC_VERSION:Mclang-*}
CMAKE_CONFIGURE_ARGS+=	-DTESTS:BOOL=FALSE
.endif

PLIST_VARS+=	objcxx
.if ${OPSYS} != "FreeBSD" && ${OPSYS} != "NetBSD"
PLIST.objcxx=	yes
.endif

.include "../../devel/cmake/build.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/robin-map/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../mk/compiler/clang.mk"
.include "../../mk/bsd.pkg.mk"
