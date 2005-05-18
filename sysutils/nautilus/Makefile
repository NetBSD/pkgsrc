# $NetBSD: Makefile,v 1.46 2005/05/18 17:23:05 jmmv Exp $
#

DISTNAME=		nautilus-2.10.1
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/nautilus/2.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/nautilus/
COMMENT=		Nautilus file manager for GNOME2

USE_PKGLOCALEDIR=	yes
USE_DIRS+=		xdg-1.1
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libnautilus-extension/libnautilus-extension.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

GCONF2_SCHEMAS=		apps_nautilus_preferences.schemas

BUILDLINK_DEPENDS.eel2+=	eel2>=2.10.1
BUILDLINK_DEPENDS.glib2+=	glib2>=2.6.0
BUILDLINK_DEPENDS.gnome-vfs2+=	gnome-vfs2>=2.10.0

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/eel2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/nautilus/extensions-1.0

.include "../../mk/bsd.pkg.mk"
