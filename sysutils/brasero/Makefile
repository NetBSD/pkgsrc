# $NetBSD: Makefile,v 1.7 2009/06/16 22:40:06 bjs Exp $
#

DISTNAME=	brasero-2.26.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/brasero/2.26/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.gnome.org/brasero/
COMMENT=	Disc-burning software for the GNOME desktop
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

# gnome-common provides m4 files we need
#
BUILD_DEPENDS+=         gnome-common>=2.26.0:../../devel/gnome-common

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake intltool gawk msgfmt
USE_TOOLS+=	autoreconf autoconf automake
USE_DIRS+=	gnome2-1.6

CONFIGURE_ARGS+=	--disable-inotify

GCONF_SCHEMAS+=		brasero.schemas
PKGCONFIG_OVERRIDE+=	libbrasero-media.pc.in

# sent upstream in http://bugzilla.gnome.org/show_bug.cgi?id=583332
post-extract:
	cp ${FILESDIR}/scsi-netbsd.c ${WRKSRC}/libbrasero-media/

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.10
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer0.10+=		gstreamer0.10>=0.10.15
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
