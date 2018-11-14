# $NetBSD: Makefile,v 1.44 2018/11/14 22:21:23 kleink Exp $

DISTNAME=	gedit-3.22.1
PKGREVISION=	6
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gedit/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://wiki.gnome.org/Apps/Gedit
COMMENT=	Lightweight GNOME UTF-8 text editor
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	data/gedit.pc.in
PY_PATCHPLIST=		yes
#PY_PEP3147=		no
PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON+=	plugins/externaltools/data/send-to-fpaste.tool.in

CONFIGURE_ARGS+=	--disable-updater
CONFIGURE_ARGS+=	--disable-deprecations
CONFIGURE_ARGS+=	--disable-maintainer-mode

.include "options.mk"

DEPENDS+=	adwaita-icon-theme-[0-9]*:../../graphics/adwaita-icon-theme
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
BUILD_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.libpeas+=	libpeas>=1.14.1
.include "../../devel/libpeas/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.44.0
.include "../../devel/glib2/schemas.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.21.3
.include "../../x11/gtk3/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtksourceview3+=	gtksourceview3>=3.21.2
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
