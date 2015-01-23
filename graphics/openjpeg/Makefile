# $NetBSD: Makefile,v 1.11 2015/01/23 17:15:09 pho Exp $

DISTNAME=	openjpeg-2.1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openjpeg.mirror/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openjpeg.org/
COMMENT=	JPEG 2000 library
LICENSE=	2-clause-bsd

USE_CMAKE=	yes
CMAKE_ARGS+=	-DOPENJPEG_INSTALL_MAN_DIR=${PKGMANDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
