# $NetBSD: nextpnr.mk,v 1.7 2025/12/25 16:32:53 ryoon Exp $

NEXTPNR_VERSION=0.9
DISTNAME=	nextpnr-${NEXTPNR_VERSION}
PKGNAME=	nextpnr-${NEXTPNR_TARGET}-${NEXTPNR_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=YosysHQ/}
GITHUB_PROJECT=	nextpnr
GITHUB_TAG=	${DISTNAME}
WRKSRC=		${WRKDIR}/nextpnr-${DISTNAME}

#PKGREVISION?=	2

MAINTAINER?=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/YosysHQ/nextpnr
COMMENT?=	A portable FPGA place and route tool
LICENSE=	isc

DISTINFO_FILE?=	${.CURDIR}/../../devel/nextpnr/distinfo
PATCHDIR?=	${.CURDIR}/../../devel/nextpnr/patches

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCURRENT_GIT_VERSION=${NEXTPNR_VERSION}
CMAKE_CONFIGURE_ARGS+=	-DARCH=${NEXTPNR_TARGET}
.if defined(NEXTPNR_TARGET_ARGS)
CMAKE_CONFIGURE_ARGS+=	${NEXTPNR_TARGET_ARGS}
.endif

.include "../../devel/cmake/build.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
