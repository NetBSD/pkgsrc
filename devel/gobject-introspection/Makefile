# $NetBSD: Makefile,v 1.96 2025/01/14 13:17:12 adam Exp $

DISTNAME=	gobject-introspection-1.82.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gobject-introspection/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gi.readthedocs.io/en/latest/
COMMENT=	GObject Introspection
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} > 311
# https://gitlab.gnome.org/GNOME/gobject-introspection/-/issues/395
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
.endif

USE_TOOLS+=	pkg-config flex bison

MESON_ARGS+=	-Dpython=${PYTHONBIN}
MESON_ARGS+=	-Ddoctool=disabled

PKGCONFIG_OVERRIDE+=	output/meson-private/gobject-introspection-1.0.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gobject-introspection-no-export-1.0.pc

PKGCONFIG_OVERRIDE_STAGE=	post-build

SUBST_CLASSES+=		libdirs
SUBST_STAGE.libdirs=	pre-configure
SUBST_FILES.libdirs=	giscanner/ccompiler.py
SUBST_FILES.libdirs+=	girepository/gitypelib.c
SUBST_VARS.libdirs=	_OPSYS_LIB_DIRS
SUBST_VARS.libdirs+=	PREFIX

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/girepository
# For Darwin
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/girepository

# Disable cache to keep fake homedir clean
MAKE_ENV+=	GI_SCANNER_DISABLE_CACHE=yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/output/gir/*.typelib ${DESTDIR}${PREFIX}/lib/girepository-1.0
	${INSTALL_DATA} ${WRKSRC}/output/gir/*.gir ${DESTDIR}${PREFIX}/share/gir-1.0

BUILDLINK_API_DEPENDS.glib2+= glib2>=2.82
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libffi+= libffi>=3.0.0
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
