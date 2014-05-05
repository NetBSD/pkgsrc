# $NetBSD: Makefile,v 1.83 2014/05/05 00:47:58 ryoon Exp $

DISTNAME=	gthumb-2.14.4
PKGREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gthumb/2.14/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://gthumb.sourceforge.net/
COMMENT=	Image viewer and browser for the GNOME Desktop
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt pkg-config gmake bison
GNU_CONFIGURE=		yes

GCONF_SCHEMAS+=	gthumb.schemas
GCONF_SCHEMAS+=	gthumb-comments.schemas gthumb-image-viewer.schemas
GCONF_SCHEMAS+=	gthumb-importer.schemas gthumb-pixbuf-savers.schemas
GCONF_SCHEMAS+=	gthumb-slideshow.schemas gthumb_convert_format.schemas
GCONF_SCHEMAS+=	gthumb_crop_options.schemas gthumb_image_print.schemas
GCONF_SCHEMAS+=	gthumb_photo_importer.schemas gthumb_rename_series.schemas
GCONF_SCHEMAS+=	gthumb_resize_images.schemas gthumb_resize_options.schemas
GCONF_SCHEMAS+=	gthumb_webalbums.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
#.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../mk/omf-scrollkeeper.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.gtk2:Mx11)
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.endif
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
