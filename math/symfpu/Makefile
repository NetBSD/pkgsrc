# $NetBSD: Makefile,v 1.1 2026/07/02 19:34:01 alnsn Exp $

DISTNAME=	symfpu-1.2.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=martin-cs/}
GITHUB_TAG=	symfpu-${PKGVERSION_NOREV}-dual-license

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/martin-cs/symfpu/
COMMENT=	Implementation of IEEE-754 / SMT-LIB floating-point
LICENSE=	modified-bsd OR gnu-gpl-v3

# Only for Intel because symfpu.a is built with
# -msse2 -mfpmath=sse -mfma -mno-fma4.
# TODO Check status on other platforms.
ONLY_FOR_PLATFORM=	*-*-x86_64 *-*-i386

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_JOBS_SAFE=	no
BUILD_TARGET=	subdirs symfpu.a

INSTALLATION_DIRS=	include/symfpu/core include/symfpu/utils lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/core/*.h ${DESTDIR}${PREFIX}/include/symfpu/core
	${INSTALL_DATA} ${WRKSRC}/utils/*.h ${DESTDIR}${PREFIX}/include/symfpu/utils
	${INSTALL_DATA} ${WRKSRC}/symfpu.a ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
