# $NetBSD: Makefile,v 1.6 2004/04/25 11:47:41 dillo Exp $
#

DISTNAME=	img2eps-0.1
PKGREVISION=	1
CATEGORIES=	print graphics
MASTER_SITES=	http://www.nih.at/img2eps/
MASTER_SITES+=	http://eris.giga.or.at/pub/nih/img2eps/
MASTER_SITES+=	http://sunsite.univie.ac.at/pub/nih/img2eps/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.nih.at/img2eps/
COMMENT=	Convert raster images to EPS files

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
TEST_TARGET=	check

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
