# $NetBSD: Makefile,v 1.35 2020/11/04 08:36:52 triaxx Exp $

DISTNAME=	libobjc2-1.8.1
PKGNAME=	${DISTNAME:S/libobjc2/gnustep-objc/}
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=libs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gnustep/libobjc2
COMMENT=	Objective-C runtime
LICENSE=	mit

USE_LANGUAGES=			objc c++11
USE_TOOLS+=			gmake cmake
MAKE_FILE=			GNUmakefile
MAKE_ENV+=			ADDITIONAL_LDFLAGS=-lpthread
MAKE_ENV+=			LIBOBJC=libobjc
MAKE_ENV+=			LIBOBJCXX=libobjcxx
MAKE_ENV+=			VERSION=4.6
MAKE_ENV+=			MAJOR_VERSION=4
MAKE_ENV+=			MINOR_VERSION=6

INSTALLATION_DIRS=		lib include/objc

do-configure:
	cd ${WRKSRC} && ${CMAKE} -Wno-dev ${CMAKE_ARGS} .

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../mk/compiler.mk"

.include "../../mk/bsd.prefs.mk"

# Building tests with GCC is not supported.
.if empty(CC_VERSION:Mclang-*)
CMAKE_ARGS+=	-DTESTS:BOOL=FALSE
.endif

PLIST_VARS+=	objcxx
.if ${OPSYS} != "FreeBSD"
PLIST.objcxx=	yes
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
