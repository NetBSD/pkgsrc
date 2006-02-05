# $NetBSD: Makefile,v 1.11 2006/02/05 23:10:37 joerg Exp $
#

DISTNAME=	img2eps-0.2
PKGREVISION=	1
CATEGORIES=	print graphics
MASTER_SITES=	http://www.nih.at/img2eps/
MASTER_SITES+=	http://eris.giga.or.at/pub/nih/img2eps/
MASTER_SITES+=	http://sunsite.univie.ac.at/pub/nih/img2eps/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.nih.at/img2eps/
COMMENT=	Convert raster images to EPS files

GNU_CONFIGURE=	YES
TEST_TARGET=	check

.include "options.mk"

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
