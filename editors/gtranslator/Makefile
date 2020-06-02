# $NetBSD: Makefile,v 1.81 2020/06/02 08:23:43 adam Exp $

DISTNAME=	gtranslator-3.32.1
PKGREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtranslator/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Gtranslator
COMMENT=	Gettext po file editor for the GNOME desktop environment
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	gettext-tools-[0-9]*:../../devel/gettext-tools

USE_TOOLS+=		gmake intltool pkg-config

REPLACE_PYTHON+=	build-aux/meson/meson_post_install.py

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/libgda/buildlink3.mk"
.include "../../devel/gdl/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/gspell/buildlink3.mk"
.include "../../x11/gtksourceview4/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"

.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
