# $NetBSD: Makefile,v 1.6 2025/10/23 09:36:19 adam Exp $

DISTNAME=	lpcnetfreedv-0.5
CATEGORIES=	ham
NNDISTFILE=	lpcnet_191005_v1.0.tgz
DISTFILES=	${DEFAULT_DISTFILES} ${NNDISTFILE}
MASTER_SITES=	${MASTER_SITE_GITHUB:=drowe67/}
GITHUB_PROJECT=	LPCNet
GITHUB_TAG=	v${PKGVERSION_NOREV}

SITES.${NNDISTFILE}=	http://rowetel.com/downloads/deep/

MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	https://github.com/drowe67/LPCNet
COMMENT=	LPCNet library for use by FreeDV
LICENSE=	modified-bsd

# \todo File a bug upstream about not passing --std=c99.
# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

USE_TOOLS+=	tar pkg-config

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

CMAKE_CONFIGURE_ARGS+=	-DBUILD_OSX_UNIVERSAL=OFF
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5
CMAKE_CONFIGURE_ARGS+=	-DDISABLE_CPU_OPTIMIZATION=ON

# \todo File a bug upstream; this seems like it should not be needed.
pre-configure:
	${MKDIR} ${WRKSRC}/${CMAKE_BUILD_DIR}
	${CP} ${DISTDIR}/${NNDISTFILE} ${WRKSRC}/${CMAKE_BUILD_DIR}

.include "../../devel/cmake/build.mk"
.include "../../ham/codec2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
