# $NetBSD: Makefile,v 1.136 2023/11/14 14:02:36 wiz Exp $

DISTNAME=	totem-3.34.1
PKGREVISION=	27
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/totem/3.34/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Videos
COMMENT=	Movie player designed for GNOME
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config msgfmt xgettext itstool
USE_TOOLS+=	pod2man

MESON_ARGS+=	-Denable-python=no

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE+=	data/totem.pc.in

# workaround for build failure
# https://gitlab.gnome.org/GNOME/json-glib/issues/35
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/src

.include "../../devel/meson/build.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../net/grilo/buildlink3.mk"
.include "../../multimedia/clutter-gst/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../multimedia/totem-pl-parser/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
