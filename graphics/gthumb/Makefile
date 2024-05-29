# $NetBSD: Makefile,v 1.123 2024/05/29 16:32:54 adam Exp $

DISTNAME=	gthumb-3.12.2
PKGREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gthumb/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/action/show/Apps/Gthumb
COMMENT=	Image viewer and browser for the GNOME Desktop
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		bison intltool itstool msgfmt pkg-config

LDFLAGS+=	${LINKER_RPATH_FLAG}${PREFIX}/lib/gthumb/extensions

# TODO: add options for
# - clutter
# - colord
# - gstreamer
# - libchamplain
# - webp
# - jxl
# - libraw
# - librsvg2
# - libheif
# - web services: webkit-gtk, libsecret
# - libbrasero

.include "../../devel/glib2/schemas.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
