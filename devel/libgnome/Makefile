# $NetBSD: Makefile,v 1.15 2003/09/25 02:56:01 danw Exp $
#

DISTNAME=	libgnome-2.2.3
PKGREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnome/2.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Core GNOME2 library (non-graphical)

DEPENDS=	docbook>=4.2:../../textproc/docbook
BUILD_USES_MSGFMT=	YES

BUILDLINK_DEPENDS.esound=	esound>=0.2.26

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_PKGINSTALL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libgnome/libgnome-2.0.pc.in

CONFIGURE_ARGS= 	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

OWN_DIRS=	${PKG_SYSCONFDIR}/sound/events

EGDIR=		${PREFIX}/share/examples/libgnome
.if defined(PKG_SYSCONFDIR.gnome-vfs2)
CONF_FILES=	${EGDIR}/gnome-vfs-2.0/modules/help-methods.conf \
		${PKG_SYSCONFDIR.gnome-vfs2}/gnome-vfs-2.0/modules/help-modules.conf
.else
CONF_FILES=	${EGDIR}/gnome-vfs-2.0/modules/help-methods.conf \
		${PKG_SYSCONFDIR}/gnome-vfs-2.0/modules/help-modules.conf
.endif
CONF_FILES+=	${EGDIR}/sound/events/gnome-2.soundlist \
		${PKG_SYSCONFDIR}/sound/events/gnome-2.soundlist
CONF_FILES+=	${EGDIR}/sound/events/gtk-events-2.soundlist \
		${PKG_SYSCONFDIR}/sound/events/gtk-events-2.soundlist

GCONF2_SCHEMAS= 	desktop_gnome_accessibility_keyboard.schemas
GCONF2_SCHEMAS+=	desktop_gnome_applications_browser.schemas
GCONF2_SCHEMAS+=	desktop_gnome_applications_help_viewer.schemas
GCONF2_SCHEMAS+=	desktop_gnome_applications_terminal.schemas
GCONF2_SCHEMAS+=	desktop_gnome_applications_window_manager.schemas
GCONF2_SCHEMAS+=	desktop_gnome_background.schemas
GCONF2_SCHEMAS+=	desktop_gnome_file_views.schemas
GCONF2_SCHEMAS+=	desktop_gnome_interface.schemas
GCONF2_SCHEMAS+=	desktop_gnome_peripherals_keyboard.schemas
GCONF2_SCHEMAS+=	desktop_gnome_peripherals_mouse.schemas
GCONF2_SCHEMAS+=	desktop_gnome_sound.schemas
GCONF2_SCHEMAS+=	desktop_gnome_thumbnailers.schemas
GCONF2_SCHEMAS+=	desktop_gnome_url_handlers.schemas

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../audio/esound/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
