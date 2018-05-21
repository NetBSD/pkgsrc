# $NetBSD: Makefile,v 1.22 2018/05/21 20:03:56 adam Exp $

DISTNAME=	x265_2.8
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	multimedia
MASTER_SITES=	https://bitbucket.org/multicoreware/x265/downloads/
MASTER_SITES+=	http://download.videolan.org/videolan/x265/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.x265.org/
COMMENT=	High Efficiency Video Coding (HEVC)
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}/source
BUILD_DEPENDS+=	nasm>=2.13.0:../../devel/nasm

CMAKE_ARGS+=	-DENABLE_PIC=ON

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

.include "../../mk/bsd.pkg.mk"
