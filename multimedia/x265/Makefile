# $NetBSD: Makefile,v 1.30 2020/05/30 06:10:40 adam Exp $

DISTNAME=	x265_3.4
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	multimedia
MASTER_SITES=	https://bitbucket.org/multicoreware/x265/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.x265.org/
COMMENT=	High Efficiency Video Coding (HEVC)
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}/source
.if ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=	nasm>=2.13.0:../../devel/nasm
.endif

CMAKE_ARGS+=	-DENABLE_PIC=ON

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
