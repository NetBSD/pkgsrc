# $NetBSD: Makefile,v 1.45 2022/02/02 14:48:18 wiz Exp $

DISTNAME=	openexr-3.1.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=openexr/}
GITHUB_PROJECT=	openexr
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.openexr.com/
COMMENT=	High dynamic-range (HDR) image file format library and tools
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++14

# C++14
GCC_REQD+=	6

PKGCONFIG_OVERRIDE=	cmake/OpenEXR.pc.in

PTHREAD_OPTS=	require

CHECK_PORTABILITY_SKIP+=	Contrib/DtexToExr/bootstrap
CHECK_PORTABILITY_SKIP+=	util/reformat.sh

.include "../../mk/pthread.buildlink3.mk"

#LIBS.SunOS+=	-lm
#LIBS.IRIX+=	-lmx

.include "../../devel/zlib/buildlink3.mk"
.include "../../math/imath/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
