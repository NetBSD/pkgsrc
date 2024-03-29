# $NetBSD: Makefile,v 1.39 2023/08/23 11:57:05 pho Exp $

DISTNAME=	libobjc2-2.1.0
PKGNAME=	${DISTNAME:S/libobjc2/gnustep-objc/}
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GITHUB:=gnustep/}
GITHUB_PROJECT=	libobjc2
GITHUB_TAG=	v2.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gnustep/libobjc2
COMMENT=	Objective-C runtime
LICENSE=	mit

TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang

USE_LANGUAGES=			objc c++11
USE_TOOLS+=			gmake cmake pax
USE_CMAKE=			yes
LDFLAGS+=			-lm -lunwind -lstdc++
MAKE_FILE=			Makefile
MAKE_ENV+=			ADDITIONAL_LDFLAGS="-lpthread"
MAKE_ENV+=			LIBOBJC=libobjc
MAKE_ENV+=			LIBOBJCXX=libobjcxx
MAKE_ENV+=			VERSION=4.6
MAKE_ENV+=			MAJOR_VERSION=4
MAKE_ENV+=			MINOR_VERSION=6

INSTALLATION_DIRS=		lib include/objc

post-extract:
	cd ${BUILDLINK_PREFIX.robin-map} && \
 	    pax -rwpam include/tsl ${WRKSRC}/third_party/robin-map/

do-configure:
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE} -Wno-dev ${CMAKE_ARGS} .

.include "../../mk/compiler.mk"

.include "../../mk/bsd.prefs.mk"

# Building tests with GCC is not supported.
.if empty(CC_VERSION:Mclang-*)
CMAKE_ARGS+=	-DTESTS:BOOL=FALSE
.endif

PLIST_VARS+=	objcxx
.if ${OPSYS} != "FreeBSD" && ${OPSYS} != "NetBSD"
PLIST.objcxx=	yes
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/robin-map/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../mk/compiler/clang.mk"
.include "../../mk/bsd.pkg.mk"
