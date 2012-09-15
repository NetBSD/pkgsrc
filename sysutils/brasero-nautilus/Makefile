# $NetBSD: Makefile,v 1.21 2012/09/15 10:06:21 obache Exp $
#

DISTNAME=	brasero-2.32.1
PKGNAME=	brasero-nautilus-2.32.1
PKGREVISION=	12
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/brasero/2.32/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.gnome.org/brasero/
COMMENT=	Nautilus plugin for brasero
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DISTINFO_FILE=	${.CURDIR}/../brasero/distinfo
PATCHDIR=	${.CURDIR}/../brasero/patches
FILESDIR=	${.CURDIR}/../brasero/files

# gnome-common provides m4 files we need
#
BUILD_DEPENDS+=         gnome-common>=2.26.0:../../devel/gnome-common

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake intltool gawk msgfmt

CONFIGURE_ARGS+=	--disable-inotify
BUILD_DIRS=		${WRKSRC}/nautilus
INSTALL_DIRS=		${WRKSRC}/nautilus

.include "../../sysutils/brasero/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.10
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer0.10+=		gstreamer0.10>=0.10.15
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
