# $NetBSD: Makefile,v 1.17 2017/02/25 08:32:18 adam Exp $

DISTNAME=	x265_2.3
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	multimedia
MASTER_SITES=	https://bitbucket.org/multicoreware/x265/downloads/
MASTER_SITES+=	http://download.videolan.org/videolan/x265/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.x265.org/
COMMENT=	High Efficiency Video Coding (HEVC)
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME}/source
BUILD_DEPENDS+=	yasm>=1.0.0:../../devel/yasm

CMAKE_ARGS+=	-DENABLE_PIC=ON

USE_CMAKE=		yes
USE_LANGUAGES=		c c++

.include "../../mk/bsd.pkg.mk"
