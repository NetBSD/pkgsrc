# $NetBSD: Makefile,v 1.174 2026/10/12 14:28:47 adam Exp $

DISTNAME=	file-roller-44.7
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
CATEGORIES=	archivers gnome
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/FileRoller
COMMENT=	Archive manager for the GNOME desktop environment
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	msgfmt pkg-config itstool

MESON_ARGS+=	-Dnautilus-actions=disabled
MESON_ARGS+=	-Dpackagekit=false

.include "../../mk/bsd.prefs.mk"

# msgfmt: unknown option -- xml
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.msgfmt=
.endif

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
