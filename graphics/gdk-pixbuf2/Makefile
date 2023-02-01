# $NetBSD: Makefile,v 1.60 2023/02/01 03:15:00 khorben Exp $

DISTNAME=	gdk-pixbuf-2.42.10
PKGNAME=	${DISTNAME:S/pixbuf/pixbuf2/}
PKGREVISION=	2
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdk-pixbuf/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.gnome.org/gdk-pixbuf
COMMENT=	Library for image loading and manipulation
LICENSE=	gnu-gpl-v2

# for man pages
TOOL_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

CONFLICTS+=	gtk2+<2.22

USE_TOOLS+=	pkg-config xgettext
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gdk-pixbuf
# For Darwin
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/gdk-pixbuf

SUBST_CLASSES+=		rst2man
SUBST_MESSAGE.rst2man=	Fixing rst2man name used by pkgsrc due to versioning.
SUBST_STAGE.rst2man=	pre-configure
SUBST_FILES.rst2man=	docs/meson.build
SUBST_SED.rst2man=	-e "s,'rst2man','rst2man-${PYVERSSUFFIX}',g"

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		dyld
SUBST_STAGE.dyld=	pre-configure
SUBST_FILES.dyld=	gdk-pixbuf/meson.build \
			tests/meson.build \
			thumbnailer/meson.build
.if ${OPSYS} == "Darwin"
SUBST_SED.dyld=		-e 's|@LD_LIBRARY_PATH@|DYLD_LIBRARY_PATH|g'
.else
SUBST_SED.dyld=		-e 's|@LD_LIBRARY_PATH@|LD_LIBRARY_PATH|g'
.endif

MESON_ARGS+=			-D installed_tests=false
PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE=		output/meson-private/gdk-pixbuf-2.0.pc

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

.include "../../lang/python/tool.mk"

_BUILDING_GTK2= yes
.include "loaders.mk"

.include "../../devel/meson/build.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/py-gi-docgen/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+= glib2>=2.37.2
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection:= build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
