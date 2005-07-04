# $NetBSD: Makefile,v 1.7 2005/07/04 19:57:01 drochner Exp $

DISTNAME=	cinepaint-0.19-1
PKGNAME=	cinepaint-0.19.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cinepaint/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://cinepaint.sourceforge.net/
COMMENT=	Motion picture painting and image retouching program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

BUILDLINK_DEPENDS.lcms+=	lcms>=1.13 # needs _cmsLCMScolorSpace
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
