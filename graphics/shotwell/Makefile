# $NetBSD: Makefile,v 1.123 2021/09/29 19:00:47 adam Exp $

DISTNAME=	shotwell-0.30.8
PKGREVISION=	16
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/shotwell/0.30/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Shotwell
COMMENT=	Photo organizer for the GNOME desktop
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config msgfmt xgettext itstool

MESON_ARGS+=	-Dudev=false

# uses python3
PYTHON_VERSIONS_INCOMPATIBLE=	27

# XXX msgfmt: unknown option -- desktop
_TOOLS_USE_PKGSRC.msgfmt=	yes

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/gexiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/libgdata/buildlink3.mk"
.include "../../security/gcr/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
