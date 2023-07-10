# $NetBSD: Makefile,v 1.2 2023/07/10 08:55:02 nia Exp $

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

# error: 'for' loop initial declarations are only allowed in C99 mode
USE_LANGUAGES=	c99
USE_TOOLS+=	tar pkg-config

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

USE_CMAKE=	yes
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..
CMAKE_ARGS+=    -DDISABLE_CPU_OPTIMIZATION=TRUE
#CMAKE_ARGS+=    -DAVX2=1 -DAVX=1
#CMAKE_ARGS+=    -DNEON=1

pre-configure:
	${MKDIR} ${WRKSRC}/build
	${CP} ${DISTDIR}/${NNDISTFILE} ${WRKSRC}/build/

.include "../../ham/codec2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
