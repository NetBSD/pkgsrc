# $NetBSD: Makefile,v 1.38 2012/10/02 17:11:07 tron Exp $

DISTNAME=	cinepaint-0.22-1
PKGNAME=	cinepaint-0.22.1
PKGREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cinepaint/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.cinepaint.org/
COMMENT=	Motion picture painting and image retouching program

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config msgfmt gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gtk2
CONFIGURE_ARGS+=	--without-python

PKGCONFIG_OVERRIDE=	cinepaint-gtk.pc.in

BUILDLINK_API_DEPENDS.lcms+=	lcms>=1.13 # needs _cmsLCMScolorSpace
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
