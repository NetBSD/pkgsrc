# $NetBSD: Makefile,v 1.4 2024/08/19 17:29:29 gdt Exp $

# https://github.com/drowe67/LPCNet/archive/v0.2.tar.gz
# http://rowetel.com/downloads/deep/lpcnet_191005_v1.0.tgz
DISTNAME=	lpcnetfreedv-0.2
CATEGORIES=	ham
NNDISTFILE=	lpcnet_191005_v1.0.tgz
DISTFILES=	${DEFAULT_DISTFILES} ${NNDISTFILE}
SITES.${NNDISTFILE}=	http://rowetel.com/downloads/deep/
MASTER_SITES=	${MASTER_SITE_GITHUB:=drowe67/}
GITHUB_PROJECT=	LPCNet
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dbj@NetBSD.org
#HOMEPAGE=	https://people.xiph.org/~jm/demo/lpcnet/
HOMEPAGE=	https://github.com/drowe67/LPCNet
COMMENT=	LPCNet library for use by FreeDV
LICENSE=	modified-bsd

# \todo File a bug upstream about not passing --std=c99.
# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

USE_TOOLS+=	tar pkg-config

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../devel/cmake/build.mk"
CMAKE_CONFIGURE_ARGS+=    -DDISABLE_CPU_OPTIMIZATION=TRUE
#CMAKE_CONFIGURE_ARGS+=    -DAVX2=1 -DAVX=1
#CMAKE_CONFIGURE_ARGS+=    -DNEON=1

# \todo File a bug upstream; this seems like it should not be needed.
pre-configure:
	${MKDIR} ${WRKSRC}/${CMAKE_BUILD_DIR}
	${CP} ${DISTDIR}/${NNDISTFILE} ${WRKSRC}/${CMAKE_BUILD_DIR}

.include "../../ham/codec2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
