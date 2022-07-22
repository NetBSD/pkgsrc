# $NetBSD: Makefile,v 1.104 2022/07/22 17:07:12 micha Exp $

DISTNAME=	cheese-3.34.0
PKGREVISION=	11
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/cheese/3.34/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Cheese
COMMENT=	Use your webcam to take photos and videos
LICENSE=	gnu-gpl-v2

DEPENDS+=	gst-plugins1-v4l2-[0-9]*:../../multimedia/gst-plugins1-v4l2

BROKEN+=	"Incompatible with latest Vala, new versions hang at startup"

USE_TOOLS+=	pkg-config msgfmt xgettext itstool

MESON_ARGS+=	-Dgtk_doc=false
MESON_ARGS+=	-Dman=false

PYTHON_FOR_BUILD_ONLY=	tool

# workaround for build failure
# https://gitlab.gnome.org/GNOME/json-glib/issues/35
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/libcheese

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/cheese.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/cheese-gtk.pc

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
BUILDLINK_DEPMETHOD.gobject-introspection?=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
BUILDLINK_DEPMETHOD.vala?=	build
.include "../../lang/vala/buildlink3.mk"
.include "../../multimedia/clutter-gst/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../multimedia/gnome-video-effects/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
