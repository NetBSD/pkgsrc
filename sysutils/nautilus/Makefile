# $NetBSD: Makefile,v 1.71 2006/09/15 15:11:18 jmmv Exp $
#

DISTNAME=		nautilus-2.16.0
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/nautilus/2.16/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/nautilus/
COMMENT=		Nautilus file manager for GNOME2

USE_PKGLOCALEDIR=	yes
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libnautilus-extension/libnautilus-extension.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

GCONF2_SCHEMAS=		apps_nautilus_preferences.schemas

BUILDLINK_API_DEPENDS.eel2+=	eel2>=2.15.91
BUILDLINK_API_DEPENDS.esound+=	esound>=0.2.27
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.0
BUILDLINK_API_DEPENDS.gnome-vfs2+=	gnome-vfs2>=2.14.2
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
BUILDLINK_API_DEPENDS.startup-notification+=	startup-notification>=0.8

.include "../../audio/esound/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/eel2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/nautilus/extensions-1.0

.include "../../mk/bsd.pkg.mk"
