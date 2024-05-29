# $NetBSD: Makefile,v 1.40 2024/05/29 16:32:52 adam Exp $

DISTNAME=	gimp-2.99.18
PKGNAME=	${DISTNAME:S/gimp/gimp-devel/}
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	https://download.gimp.org/pub/gimp/v${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.gimp.org/
COMMENT=	The GNU image manipulation program (development version)
LICENSE=	gnu-lgpl-v3 AND gnu-gpl-v3

TOOL_DEPENDS+=	vera-ttf-[0-9]*:../../fonts/vera-ttf
TOOL_DEPENDS+=	gettext-tools>=0.19:../../devel/gettext-tools
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
DEPENDS+=	glib-networking>=2.36.2:../../net/glib-networking
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
#DEPENDS+=	gjs-[0-9]*:../../lang/gjs

CONFLICTS+=	gimp-[0-9]*

USE_LANGUAGES+=		c c++14
USE_PKGLOCALEDIR=	yes

USE_TOOLS+=		pkg-config perl
USE_TOOLS+=		msgfmt msgmerge xgettext
USE_TOOLS+=		gdbus-codegen

PKGCONFIG_OVERRIDE+=		output/meson-private/*.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

UNLIMIT_RESOURCES+=	datasize

# Disable documentation for developers explicitly.
MESON_ARGS+=	-Dgi-docgen=disabled
MESON_ARGS+=	-Dg-ir-doc=false

# example files
CHECK_INTERPRETER_SKIP+=	lib/gimp/2.99/extensions/org.gimp.extension.goat-exercises/*
CHECK_INTERPRETER_SKIP+=	lib/gimp/2.99/plug-ins/test-sphere-v3/test-sphere-v3.scm
CHECK_INTERPRETER_SKIP+=	lib/gimp/2.99/plug-ins/ts-helloworld/ts-helloworld.scm

REPLACE_PYTHON+=	plug-ins/python/*.py
REPLACE_PYTHON+=	plug-ins/python/*/*.py
REPLACE_PYTHON+=	tools/*.py
REPLACE_PYTHON+=	extensions/goat-exercises/goat-exercise-py3.py

# GCC 4.x C++14 support is not new enough.
GCC_REQD+=	5

MAKE_DIRS+=		${PKG_SYSCONFDIR}/gimp/2.99
EGDIR=			${PREFIX}/share/examples/gimp
.for f in controllerrc gimp.css gimprc sessionrc templaterc toolrc unitrc
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/gimp/2.99/${f}
.endfor

# checking for xgettext version (>= 0.19)... no
_TOOLS_USE_PKGSRC.xgettext=	yes

.include "../../mk/bsd.prefs.mk"

# msgfmt: unknown option -- desktop
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.msgfmt=
.endif

INSTALLATION_DIRS=	share/examples

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/gimp/2.99 ${DESTDIR}${PREFIX}/share/examples/gimp

.include "options.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/appstream-glib/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.12.4
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.babl+=		babl>=0.1.98
.include "../../graphics/babl/buildlink3.mk"
BUILDLINK_API_DEPENDS.gegl+=		gegl>=0.4.48
.include "../../graphics/gegl/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gexiv2+=		gexiv2>=0.14
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
BUILDLINK_API_DEPENDS.tiff+=	tiff>=4.0
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../print/ghostscript/buildlink3.mk"
.include "../../print/poppler-data/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler+=	poppler>=23.12.0
.include "../../print/poppler/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
