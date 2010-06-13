# $NetBSD: Makefile,v 1.2 2010/06/13 22:44:25 wiz Exp $
#

DISTNAME=	gipfel-0.3.2
PKGREVISION=	2
CATEGORIES=	geography graphics
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	johannes.hofmann@gmx.de
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/gipfel.html
COMMENT=	Photogrammetry For Mountain Images
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
