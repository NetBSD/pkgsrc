# $NetBSD: nextpnr.mk,v 1.1 2024/02/28 06:31:57 thorpej Exp $

NEXTPNR_VERSION=0.7
DISTNAME=	nextpnr-${NEXTPNR_VERSION}
PKGNAME=	nextpnr-${NEXTPNR_TARGET}-${NEXTPNR_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=YosysHQ/}
GITHUB_TAG=	${DISTNAME}
WRKSRC=		${WRKDIR}/nextpnr-${DISTNAME}

MAINTAINER?=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/YosysHQ/nextpnr
COMMENT?=	A portable FPGA place and route tool
LICENSE=	isc

DISTINFO_FILE?=	${.CURDIR}/../../devel/nextpnr/distinfo
PATCHDIR?=	${.CURDIR}/../../devel/nextpnr/patches

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CMAKE_ARGS+=	-DARCH=${NEXTPNR_TARGET}
.if defined(NEXTPNR_TARGET_ARGS)
CMAKE_ARGS+=	${NEXTPNR_TARGET_ARGS}
.endif

# Python 3.5 or later, including development libraries, Python 3.9 or
# later required for nextpnr-himbaechel.
PYTHON_VERSIONS_INCOMPATIBLE= 27 38

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
