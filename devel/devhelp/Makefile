# $NetBSD: Makefile,v 1.140 2020/11/05 09:07:52 ryoon Exp $

DISTNAME=	devhelp-3.34.0
PKGREVISION=	6
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/devhelp/3.34/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Devhelp
COMMENT=	Tool for browsing and searching API documentation from GNOME
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config msgfmt xgettext

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

# workaround for build failure
# https://gitlab.gnome.org/GNOME/json-glib/issues/35
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/devhelp

PYTHON_FOR_BUILD_ONLY=	tool

# XXX msgfmt: unknown option -- xml
_TOOLS_USE_PKGSRC.msgfmt=	yes

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/libdevhelp-3.0.pc

.include "../../devel/meson/build.mk"
.include "../../devel/amtk/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
