# $NetBSD: Makefile,v 1.150 2020/11/22 21:45:51 nia Exp $

DISTNAME=	nautilus-3.38.1
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
PKGREVISION=	1
CATEGORIES=	sysutils gnome
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Files
COMMENT=	Simple file manager for GNOME
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

USE_TOOLS+=	pkg-config msgfmt xgettext

DEPENDS+=	gnome-tracker-miners-[0-9]*:../../sysutils/gnome-tracker-miners

# XXX msgfmt: unknown option -- desktop
_TOOLS_USE_PKGSRC.msgfmt=	yes

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/libnautilus-extension.pc

.include "../../devel/meson/build.mk"
.include "../../archivers/gnome-autoar/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/gexiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/gnome-tracker/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
