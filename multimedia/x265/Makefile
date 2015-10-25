# $NetBSD: Makefile,v 1.10 2015/10/25 13:51:09 adam Exp $

DISTNAME=	x265_1.8
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	multimedia
MASTER_SITES=	https://bitbucket.org/multicoreware/x265/downloads/ \
		http://download.videolan.org/videolan/x265/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.x265.org/
COMMENT=	High Efficiency Video Coding (HEVC)
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/x265_11047/source
BUILD_DEPENDS+=	yasm>=1.0.0:../../devel/yasm

CMAKE_ARGS+=	-DENABLE_PIC=ON

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

.include "../../mk/bsd.pkg.mk"
