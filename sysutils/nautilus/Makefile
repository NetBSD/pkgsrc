# $NetBSD: Makefile,v 1.32 2004/04/19 15:05:00 jmmv Exp $
#

DISTNAME=		nautilus-2.6.0
PKGREVISION=		1
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/nautilus/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/nautilus/
COMMENT=		Nautilus file manager for GNOME2

DEPENDS+=		hicolor-icon-theme>=0.4:../../graphics/hicolor-icon-theme

USE_PKGLOCALEDIR=	yes
USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libnautilus/libnautilus.pc.in
PKGCONFIG_OVERRIDE+=	libnautilus-extension/libnautilus-extension.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

GCONF2_SCHEMAS=		apps_nautilus_preferences.schemas

OWN_DIRS=		${PKG_SYSCONFDIR}/X11/serverconfig
OWN_DIRS+=		${PKG_SYSCONFDIR}/X11/starthere
OWN_DIRS+=		${PKG_SYSCONFDIR}/X11/sysconfig
EGDIR=			${PREFIX}/share/examples/nautilus
CONF_FILES=
.for conffile in	X11/serverconfig/.directory \
			X11/starthere/.directory \
			X11/starthere/applications.desktop \
			X11/starthere/preferences.desktop \
			X11/starthere/serverconfig.desktop \
			X11/starthere/sysconfig.desktop \
			X11/sysconfig/.directory
CONF_FILES+=		${EGDIR}/${conffile} ${PKG_SYSCONFDIR}/${conffile}
.endfor
.undef conffile

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

.include "../../mk/bsd.pkg.mk"
