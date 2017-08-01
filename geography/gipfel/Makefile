# $NetBSD: Makefile,v 1.15 2017/08/01 17:40:11 wiz Exp $
#

DISTNAME=	gipfel-0.4.0
PKGREVISION=	2
CATEGORIES=	geography graphics
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	johannes.hofmann@gmx.de
#HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/gipfel.html
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
