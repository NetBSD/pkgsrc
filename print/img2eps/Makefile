# $NetBSD: Makefile,v 1.4 2004/01/03 18:49:51 reed Exp $
#

DISTNAME=	img2eps-0.1
PKGREVISION=	1
CATEGORIES=	print graphics
MASTER_SITES=	http://eris.giga.or.at/pub/nih/img2eps/
MASTER_SITES+=	http://sunsite.univie.ac.at/pub/nih/img2eps/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://eris.giga.or.at/pub/nih/img2eps/
COMMENT=	Convert raster images to EPS files

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
TEST_TARGET=	check

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
