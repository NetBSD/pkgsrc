# $NetBSD: Makefile,v 1.33 2004/10/03 00:13:29 tv Exp $
#

DISTNAME=	libgnome-2.8.0
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnome/2.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Core GNOME2 library (non-graphical)

DEPENDS=	docbook>=4.2:../../textproc/docbook
BUILD_USES_MSGFMT=	YES

BUILDLINK_DEPENDS.esound+=	esound>=0.2.26

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_PKGINSTALL=		YES

PKGCONFIG_OVERRIDE=	libgnome/libgnome-2.0.pc.in

CONFIGURE_ARGS= 	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

OWN_DIRS=	${PKG_SYSCONFDIR}/sound/events

EGDIR=		${PREFIX}/share/examples/libgnome
CONF_FILES=	${EGDIR}/sound/events/gnome-2.soundlist \
		${PKG_SYSCONFDIR}/sound/events/gnome-2.soundlist
CONF_FILES+=	${EGDIR}/sound/events/gtk-events-2.soundlist \
		${PKG_SYSCONFDIR}/sound/events/gtk-events-2.soundlist

GCONF2_SCHEMAS= 	desktop_gnome_accessibility_keyboard.schemas
GCONF2_SCHEMAS+=	desktop_gnome_accessibility_startup.schemas
GCONF2_SCHEMAS+=	desktop_gnome_applications_browser.schemas
GCONF2_SCHEMAS+=	desktop_gnome_applications_help_viewer.schemas
GCONF2_SCHEMAS+=	desktop_gnome_applications_terminal.schemas
GCONF2_SCHEMAS+=	desktop_gnome_applications_window_manager.schemas
GCONF2_SCHEMAS+=	desktop_gnome_background.schemas
GCONF2_SCHEMAS+=	desktop_gnome_file_views.schemas
GCONF2_SCHEMAS+=	desktop_gnome_interface.schemas
GCONF2_SCHEMAS+=	desktop_gnome_lockdown.schemas
GCONF2_SCHEMAS+=	desktop_gnome_peripherals_keyboard.schemas
GCONF2_SCHEMAS+=	desktop_gnome_peripherals_mouse.schemas
GCONF2_SCHEMAS+=	desktop_gnome_sound.schemas
GCONF2_SCHEMAS+=	desktop_gnome_thumbnailers.schemas
GCONF2_SCHEMAS+=	desktop_gnome_typing_break.schemas

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
