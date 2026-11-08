# $NetBSD: Makefile,v 1.2 2026/11/08 13:57:54 alnsn Exp $

DISTNAME=	symfpu-1.2.0
PKGREVISION=	1
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

INSTALLATION_DIRS=	lib lib/pkgconfig
INSTALLATION_DIRS+=	include/symfpu/core include/symfpu/utils

SUBST_CLASSES+=		pc
SUBST_STAGE.pc=		pre-configure
SUBST_MESSAGE.pc=	Set prefix and version in symfpu.pc.
SUBST_FILES.pc=		symfpu.pc
SUBST_VARS.pc=		PREFIX PKGVERSION_NOREV

post-extract:
	${CP} ${FILESDIR}/symfpu.pc ${WRKSRC}/symfpu.pc

do-install:
	${INSTALL_DATA} ${WRKSRC}/symfpu.pc ${DESTDIR}${PREFIX}/lib/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/core/*.h ${DESTDIR}${PREFIX}/include/symfpu/core
	${INSTALL_DATA} ${WRKSRC}/utils/*.h ${DESTDIR}${PREFIX}/include/symfpu/utils
	${INSTALL_DATA} ${WRKSRC}/symfpu.a ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
