# $NetBSD: Makefile,v 1.80 2020/02/26 15:09:26 wiz Exp $

DISTNAME=	gegl-0.4.22
CATEGORIES=	graphics
MASTER_SITES=	https://download.gimp.org/pub/gegl/0.4/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://gegl.org/
COMMENT=	Graph based image processing framework
LICENSE=	gnu-gpl-v3

MESON_ARGS+=	-Dintrospection=false
MESON_ARGS+=	-Dlibv4l=disabled
MESON_ARGS+=	-Dlibv4l2=disabled

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config xgettext
USE_TOOLS+=	bash

PKGCONFIG_OVERRIDE+=	gegl.pc.in

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		Darwin not_Darwin
.if ${OPSYS} == "Darwin"
PLIST.Darwin=		yes
PLIST_SUBST+=		SOEXT="dylib"
.else
PLIST.not_Darwin=	yes
PLIST_SUBST+=		SOEXT="so"
.endif

# ../gegl/opencl/gegl-cl-color.c:32:10: fatal error: opencl/colors.cl.h: No such file or directory
# race condition in meson?
pre-build:
	cd ${WRKSRC}/opencl && for file in $$(ls -1 | grep '\.cl$$'); do \
		${PYTHONBIN} cltostring.py "$$file" "$$file".h \
	; done

.if ${OPSYS} == "Darwin"
#
# Meson uses .dylib for Darwin shared libraries, but G_MODULE_SUFFIX
# is always .so on Unix, including Darwin.  This is under discussion
# at https://gitlab.gnome.org/GNOME/glib/issues/1413 but for now
# rename the plugins and reset their internal ID to match the new
# name.
#
post-install:
	cd ${DESTDIR}/${PREFIX}/lib/gegl-0.4 && for i in *.dylib; do \
		install_name_tool -id ${PREFIX}/lib/gegl-0.4/$${i%.dylib}.so $${i}; \
		mv "$${i}" "$${i%.dylib}.so" \
	; done
.endif

.include "options.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
BUILDLINK_API_DEPENDS.babl+=	babl>=0.1.72
.include "../../graphics/babl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
