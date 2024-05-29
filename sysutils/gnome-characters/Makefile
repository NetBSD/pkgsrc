# $NetBSD: Makefile,v 1.21 2024/05/29 16:34:25 adam Exp $

DISTNAME=	gnome-characters-3.34.0
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
PKGREVISION=	18
CATEGORIES=	sysutils gnome
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Design/Apps/CharacterMap
COMMENT=	Utility application to find and insert unusual characters
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config msgfmt xgettext

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/gjs/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
