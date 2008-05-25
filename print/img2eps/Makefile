# $NetBSD: Makefile,v 1.15 2008/05/25 13:16:11 dillo Exp $
#

DISTNAME=	img2eps-0.2
PKGREVISION=	3
CATEGORIES=	print graphics
MASTER_SITES=	http://www.nih.at/img2eps/

OWNER=		dillo@NetBSD.org
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
