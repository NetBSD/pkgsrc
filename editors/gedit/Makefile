# $NetBSD: Makefile,v 1.168 2022/06/30 11:18:20 nia Exp $

DISTNAME=	gedit-3.36.2
PKGREVISION=	10
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gedit/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://wiki.gnome.org/Apps/Gedit
COMMENT=	Lightweight GNOME UTF-8 text editor
LICENSE=	gnu-gpl-v2

PREV_PKGPATH=	editors/gedit3

USE_TOOLS+=			gettext msgfmt perl pkg-config
USE_TOOLS+=			itstool

PYTHON_VERSIONS_INCOMPATIBLE=	27
PY_PATCHPLIST=			yes
REPLACE_PYTHON+=		plugins/externaltools/data/send-to-fpaste.tool.in
REPLACE_PYTHON+=		build-aux/meson/post_install.py

MESON_ARGS+=	-Dvapi=false
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gedit

DEPENDS+=	adwaita-icon-theme-[0-9]*:../../graphics/adwaita-icon-theme
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

pre-configure:
	${FIND} ${WRKSRC}/help -type f -exec ${CHMOD} 644 {} \;


.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
BUILDLINK_API_DEPENDS.libpeas+=	libpeas>=1.14.1
.include "../../devel/libpeas/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.52
.include "../../devel/glib2/schemas.mk"
.include "../../devel/meson/build.mk"
.include "../../editors/tepl4/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../textproc/gspell/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.22
.include "../../x11/gtk3/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtksourceview4+=	gtksourceview4>=4.0.2
.include "../../x11/gtksourceview4/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
