# $NetBSD: Makefile,v 1.15 2017/08/17 20:08:33 adam Exp $

DISTNAME=	openjpeg-2.2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=uclouvain/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openjpeg.org/
COMMENT=	JPEG 2000 library
LICENSE=	2-clause-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c99 c++
CMAKE_ARGS+=	-DOPENJPEG_INSTALL_MAN_DIR=${PKGMANDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
