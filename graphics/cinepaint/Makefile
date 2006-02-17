# $NetBSD: Makefile,v 1.11 2006/02/17 23:42:35 wiz Exp $

DISTNAME=	cinepaint-0.20-2
PKGNAME=	cinepaint-0.20.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cinepaint/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://cinepaint.sourceforge.net/
COMMENT=	Motion picture painting and image retouching program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE=	cinepaint-gtk.pc.in

BUILDLINK_DEPENDS.lcms+=	lcms>=1.13 # needs _cmsLCMScolorSpace
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
