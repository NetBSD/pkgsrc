# $NetBSD: Makefile,v 1.23 2021/06/23 20:33:11 nia Exp $

DISTNAME=	openjpeg-2.4.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=uclouvain/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openjpeg.org/
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
