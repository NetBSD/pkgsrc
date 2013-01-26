# $NetBSD: Makefile,v 1.10 2013/01/26 21:37:38 adam Exp $
#

DISTNAME=	gipfel-0.3.2
PKGREVISION=	8
CATEGORIES=	geography graphics
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	johannes.hofmann@gmx.de
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/gipfel.html
COMMENT=	Photogrammetry For Mountain Images
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
