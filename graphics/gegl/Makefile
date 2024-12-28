# $NetBSD: Makefile,v 1.142 2024/12/28 09:40:01 wiz Exp $

DISTNAME=	gegl-0.4.52
CATEGORIES=	graphics
MASTER_SITES=	https://download.gimp.org/pub/gegl/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gegl.org/
COMMENT=	Graph based image processing framework
LICENSE=	gnu-gpl-v3

MESON_ARGS+=	-Dlibv4l=disabled
MESON_ARGS+=	-Dlibv4l2=disabled
# Some binaries that are required to generate docs
# are built with RPATH $ORIGIN. Disable docs explicitly.
MESON_ARGS+=	-Ddocs=false
MESON_ARGS+=	-Dgi-docgen=disabled

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash pkg-config xgettext
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gegl
# For Darwin
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/gegl

PKGCONFIG_OVERRIDE+=	output/meson-private/gegl-0.4.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gegl-sc-0.4.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		darwin notdarwin
.if ${OPSYS} == "Darwin"
PLIST_SUBST+=		SOEXT="dylib"
PLIST.darwin=		yes
PRINT_PLIST_AWK+=	{ gsub(/\.dylib$$/, ".$${SOEXT}"); }
.else
PLIST_SUBST+=		SOEXT="so"
PLIST.notdarwin=	yes
PRINT_PLIST_AWK+=	{ gsub(/\.so$$/, ".$${SOEXT}"); }
.endif

PLIST_SRC+=		${PLIST_SRC_DFLT}
.if ${MACHINE_ARCH} == "x86_64"
PRINT_PLIST_AWK+=	{ if (/x86_64-v/) $$0 = "$${PLIST.x86_64}" $$0 }
.endif

.if ${MACHINE_ARCH:Mearmv[67]*}
PLIST_SRC+=		PLIST.neon
PRINT_PLIST_AWK+=	{ if (/arm-neon/) $$0 = "$${PLIST.neon}" $$0 }
.endif

# ../gegl/opencl/gegl-cl-color.c:32:10: fatal error: opencl/colors.cl.h: No such file or directory
# race condition in meson?
pre-build:
	cd ${WRKSRC}/opencl && for file in $$(ls -1 | grep '\.cl$$'); do \
		${PYTHONBIN} cltostring.py "$$file" "$$file".h \
	; done

.include "options.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
BUILDLINK_API_DEPENDS.babl+=	babl>=0.1.92nb1
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/babl/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
