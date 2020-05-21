# $NetBSD: Makefile,v 1.70 2020/05/21 20:53:42 ryoon Exp $

DISTNAME=	cinepaint-1.0-4
PKGNAME=	cinepaint-1.0.4
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cinepaint/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.cinepaint.org/
COMMENT=	Motion picture painting and image retouching program
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND mit AND modified-bsd

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config msgfmt gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-python

PKGCONFIG_OVERRIDE=	cinepaint-gtk.pc.in

BUILDLINK_API_DEPENDS.lcms+=	lcms>=1.13 # needs _cmsLCMScolorSpace
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
