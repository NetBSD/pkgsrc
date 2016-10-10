# $NetBSD: Makefile,v 1.14 2016/10/10 17:13:42 adam Exp $

DISTNAME=	x265_2.1
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	multimedia
MASTER_SITES=	https://bitbucket.org/multicoreware/x265/downloads/ \
		http://download.videolan.org/videolan/x265/

# IMPORTANT: remove on the next update
DIST_SUBDIR=	x265

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
