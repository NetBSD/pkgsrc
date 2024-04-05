# $NetBSD: Makefile,v 1.38 2024/04/05 09:22:33 adam Exp $

DISTNAME=	x265_3.6
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	multimedia
MASTER_SITES=	https://bitbucket.org/multicoreware/x265_git/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.x265.org/
COMMENT=	High Efficiency Video Coding (HEVC)
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/source

USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DENABLE_PIC=ON
# Set version here instead of relying on git; see patch-CMakeLists.txt
CMAKE_ARGS+=	-DX265_VERSION=${PKGVERSION_NOREV}
CMAKE_ARGS+=	-DX265_LATEST_TAG=${PKGVERSION_NOREV}

.include "options.mk"

.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "i386"
.  if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && ${MACHINE_ARCH} == "i386"
# Avoid text relocations
CMAKE_ARGS+=	-DENABLE_ASSEMBLY=OFF
.  else
TOOL_DEPENDS+=	nasm>=2.13.0:../../devel/nasm
.  endif
.endif

.if ${USE_CROSS_COMPILE:tl} == "yes"
CMAKE_ARGS+=	-DCMAKE_SYSTEM:STRING=${OPSYS}-${OS_VERSION}
CMAKE_ARGS+=	-DCMAKE_SYSTEM_NAME:STRING=${OPSYS}
CMAKE_ARGS+=	-DCMAKE_SYSTEM_VERSION:STRING=${OS_VERSION}
CMAKE_ARGS+=	-DCMAKE_SYSTEM_PROCESSOR:STRING=${MACHINE_ARCH}
.endif

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
