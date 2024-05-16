# $NetBSD: Makefile,v 1.206 2024/05/16 06:14:34 wiz Exp $

DISTNAME=	rhythmbox-3.4.6
PKGREVISION=	13
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/rhythmbox/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Rhythmbox
COMMENT=	Music management application for GNOME
LICENSE=	gnu-gpl-v2

DEPENDS+=	gst-plugins1-libav-[0-9]*:../../multimedia/gst-plugins1-libav
DEPENDS+=	gst-plugins1-good-[0-9]*:../../multimedia/gst-plugins1-good
DEPENDS+=	gst-plugins1-oss-[0-9]*:../../audio/gst-plugins1-oss
DEPENDS+=	grilo-plugins-[0-9]*:../../net/grilo-plugins
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

USE_TOOLS+=		intltool itstool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../audio/libgpod/buildlink3.mk"
.include "../../sysutils/brasero/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../databases/tdb/buildlink3.mk"
.include "../../devel/check/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/totem-pl-parser/buildlink3.mk"
.include "../../net/grilo/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
