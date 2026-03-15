# $NetBSD: Makefile,v 1.430 2026/03/15 07:29:21 wiz Exp $

DISTNAME=	gimp-3.2.0
CATEGORIES=	graphics
MASTER_SITES=	https://download.gimp.org/pub/gimp/v${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.gimp.org/
COMMENT=	The GNU image manipulation program
LICENSE=	gnu-lgpl-v3 AND gnu-gpl-v3

TOOL_DEPENDS+=	vera-ttf-[0-9]*:../../fonts/vera-ttf
TOOL_DEPENDS+=	gettext-tools>=0.19:../../devel/gettext-tools
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
DEPENDS+=	glib-networking>=2.36.2:../../net/glib-networking
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
#DEPENDS+=	gjs-[0-9]*:../../lang/gjs

CONFLICTS+=	gimp-devel-[0-9]*

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes

USE_TOOLS+=		pkg-config perl realpath
USE_TOOLS+=		msgfmt msgmerge xgettext
USE_TOOLS+=		gdbus-codegen

PKGCONFIG_OVERRIDE+=		output/meson-private/*.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

UNLIMIT_RESOURCES+=	datasize

# Disable documentation for developers explicitly.
MESON_ARGS+=	-Dgi-docgen=disabled
# Do not find bin/gjs
MESON_ARGS+=	-Djavascript=disabled

# example files
CHECK_INTERPRETER_SKIP+=	lib/gimp/3.0/extensions/org.gimp.extension.goat-exercises/*
CHECK_INTERPRETER_SKIP+=	lib/gimp/3.0/plug-ins/test-sphere-v3/test-sphere-v3.scm
CHECK_INTERPRETER_SKIP+=	lib/gimp/3.0/plug-ins/ts-helloworld/ts-helloworld.scm
CHECK_PORTABILITY_SKIP+=	build/linux/appimage/*
CHECK_PORTABILITY_SKIP+=	build/windows/*

REPLACE_PYTHON+=	plug-ins/python/*.py
REPLACE_PYTHON+=	plug-ins/python/*/*.py
REPLACE_PYTHON+=	tools/*.py
REPLACE_PYTHON+=	extensions/goat-exercises/goat-exercise-py3.py

MAKE_DIRS+=		${PKG_SYSCONFDIR}/gimp/3.0
EGDIR=			${PREFIX}/share/examples/gimp
.for f in controllerrc gimp.css gimprc sessionrc templaterc toolrc unitrc
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/gimp/3.0/${f}
.endfor

INSTALLATION_DIRS=	share/examples

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
# libgimpwidgets/gimppickbutton-quartz.c: error: 'CGWindowListCreateImage' is unavailable: obsoleted in macOS 15.0
.  if ${OPSYS_VERSION} >= 150000
MAKE_ENV+=	MACOSX_DEPLOYMENT_TARGET=14.0
.  endif
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/libgimp

.PHONY: fix-modules-id
post-install: fix-modules-id
fix-modules-id:
	cd ${DESTDIR}; \
	for i in $$(${FIND} .${PREFIX}/lib -name '*.so' | ${SED} -e 's|^\./||'); do \
          install_name_tool -id /$$i $$i; \
        done
.endif

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/examples/gimp
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/gimp/3.0 ${DESTDIR}${PREFIX}/share/examples/gimp

.include "options.mk"

PLIST_VARS+=	xmc

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/appstream/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.12.4
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.babl+=		babl>=0.1.118
.include "../../graphics/babl/buildlink3.mk"
BUILDLINK_API_DEPENDS.gegl+=		gegl>=0.4.66
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
.include "../../graphics/libjxl/buildlink3.mk"
.include "../../graphics/libmypaint/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/mypaint-brushes/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
BUILDLINK_API_DEPENDS.tiff+=	tiff>=4.0
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../print/poppler-data/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler+=	poppler>=23.12.0
.include "../../print/poppler/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.gtk3:Mx11}
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
PRINT_PLIST_AWK+=       { if (/file-xmc/) $$0 = "$${PLIST.xmc}" $$0 }
PLIST.xmc=		yes
.include "../../x11/libXmu/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
