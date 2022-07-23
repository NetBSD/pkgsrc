# $NetBSD: Makefile,v 1.3 2022/07/23 09:31:57 wiz Exp $

DISTNAME=	gimp-2.99.10
PKGNAME=	${DISTNAME:S/gimp/gimp-devel/}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://download.gimp.org/pub/gimp/v${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.gimp.org/
COMMENT=	The GNU image manipulation program (development version)
LICENSE=	gnu-lgpl-v3 AND gnu-gpl-v3

BUILD_DEPENDS+=	vera-ttf-[0-9]*:../../fonts/vera-ttf
TOOL_DEPENDS+=	gettext-tools>=0.19:../../devel/gettext-tools
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
DEPENDS+=	glib-networking>=2.36.2:../../net/glib-networking
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

CONFLICTS+=	gimp-[0-9]*

USE_LANGUAGES+=		c c++14
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

USE_TOOLS+=		gmake pkg-config perl
USE_TOOLS+=		intltool msgfmt msgmerge xgettext
USE_TOOLS+=		gdbus-codegen

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-alsatest
CONFIGURE_ARGS+=	--disable-glibtest
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-linux-input

PKG_SYSCONFSUBDIR=	gimp/2.99
PKGCONFIG_OVERRIDE=	gimp.pc.in
UNLIMIT_RESOURCES+=	datasize

# https://gitlab.gnome.org/GNOME/gimp/-/issues/8377
PKGSRC_USE_STACK_CHECK=	no

# example files
CHECK_INTERPRETER_SKIP+=	lib/gimp/2.99/extensions/org.gimp.extension.goat-exercises/*

REPLACE_PYTHON+=	plug-ins/python/*.py
REPLACE_PYTHON+=	plug-ins/python/*/*.py
REPLACE_PYTHON+=	tools/*.py
REPLACE_PYTHON+=	extensions/goat-exercises/goat-exercise-py3.py

# GCC 4.x C++14 support is not new enough.
GCC_REQD+=	5

.include "../../mk/bsd.prefs.mk"

EGDIR=			${PREFIX}/share/examples/gimp-2.99
.for f in controllerrc gimp.css gimprc menurc sessionrc templaterc toolrc unitrc
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

# checking for xgettext version (>= 0.19)... no
_TOOLS_USE_PKGSRC.xgettext=	yes

# Ensure we export symbols in the linked shared object.
#LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	GIMP_DEBUG_TOOL_DIR="bin"
.else
PLIST_SUBST+=	GIMP_DEBUG_TOOL_DIR="libexec"
.endif

.include "options.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/appstream-glib/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.8.1
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.12.4
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.babl+=		babl>=0.1.92nb1
.include "../../graphics/babl/buildlink3.mk"
BUILDLINK_API_DEPENDS.gegl+=		gegl>=0.4.36nb4
.include "../../graphics/gegl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/gexiv2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libheif/buildlink3.mk"
#.include "../../wip/libjxl/buildlink3.mk"
.include "../../graphics/libmypaint/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/mypaint-brushes1/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../print/ghostscript/buildlink3.mk"
.include "../../print/poppler-data/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
