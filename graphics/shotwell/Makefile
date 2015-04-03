# $NetBSD: Makefile,v 1.64 2015/04/03 07:38:35 wiz Exp $

DISTNAME=		shotwell-0.20.2
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		https://download.gnome.org/sources/shotwell/0.20/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgrsc-users@NetBSD.org
HOMEPAGE=		https://wiki.gnome.org/Apps/Shotwell
COMMENT=		Shotwell is a photo organizer for the GNOME desktop
LICENSE=		gnu-lgpl-v2.1

BUILD_DEPENDS+=		gnome-doc-utils-[0-9]*:../../textproc/gnome-doc-utils

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake bash pkg-config msgfmt

CONFIG_SHELL=		bash
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--assume-pkgs
CONFIGURE_ENV+=		--define=NO_CAMERA
MAKE_ENV+=		VALAC=${VALAC}

REPLACE_SH+=		configure

.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgexiv2+= libgexiv2>=0.4.1
.include "../../graphics/libgexiv2/buildlink3.mk"
# 0.13.2 added shared libs
BUILDLINK_ABI_DEPENDS.libraw+= libraw>=0.13.2
.include "../../graphics/libraw/buildlink3.mk"
# Required for dealing with .svg icons. Spotted on a clean box
.include "../../graphics/librsvg/buildlink3.mk"
BUILDLINK_DEPMETHOD.vala= build
.include "../../lang/vala/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../www/webkit1-gtk3/buildlink3.mk"
.include "../../www/librest07/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libunique3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
