# $NetBSD: Makefile,v 1.118 2022/08/11 05:08:40 gutteridge Exp $

DISTNAME=	eog-40.3
PKGREVISION=	3
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/eog/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Eye of GNOME: an image viewing and cataloging program
LICENSE=	gnu-gpl-v2

PREV_PKGPATH=	graphics/eog3

USE_TOOLS+=	msgfmt pkg-config xgettext itstool

# some linux-only packaging thing
MESON_ARGS+=	-Dlibportal=false

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/eog

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/eog.pc

.include "../../devel/meson/build.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.42.0
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.22.0
.include "../../x11/gtk3/buildlink3.mk"

# "semi-optional":
.include "../../mk/jpeg.buildlink3.mk"

.include "../../devel/exempi/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libexif+= libexif>=0.6.14
.include "../../graphics/libexif/buildlink3.mk"
BUILDLINK_API_DEPENDS.librsvg+=	librsvg>=2.36.2
.include "../../graphics/librsvg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
