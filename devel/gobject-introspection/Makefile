# $NetBSD: Makefile,v 1.78 2022/01/20 17:08:33 nros Exp $

DISTNAME=	gobject-introspection-1.68.0
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gobject-introspection/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/GObjectIntrospection
COMMENT=	GObject Introspection
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_TOOLS+=	pkg-config flex bison

MESON_ARGS+=	-Dpython=${PYTHONBIN}
MESON_ARGS+=	-Ddoctool=disabled

PKGCONFIG_OVERRIDE+=	gobject-introspection-1.0.pc.in
PKGCONFIG_OVERRIDE+=	gobject-introspection-no-export-1.0.pc.in

SUBST_CLASSES+=		timet
SUBST_STAGE.timet=	pre-configure
SUBST_FILES.timet=	giscanner/ast.py
SUBST_FILES.timet+=	tests/scanner/Regress-1.0-expected.gir
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-5.99.*) || !empty(MACHINE_PLATFORM:MNetBSD-[6-9].*) || !empty(MACHINE_PLATFORM:MMirBSD-*)
SUBST_SED.timet=	-e 's,@TIMET_TYPENAME@,TYPE_INT64,g'
SUBST_SED.timet+=	-e 's,@TIMET_CTYPE@,gint64,g'
.else
SUBST_SED.timet=	-e 's,@TIMET_TYPENAME@,TYPE_LONG,g'
SUBST_SED.timet+=	-e 's,@TIMET_CTYPE@,glong,g'
.endif

SUBST_CLASSES+=		libdirs
SUBST_STAGE.libdirs=	pre-configure
SUBST_FILES.libdirs=	giscanner/ccompiler.py
SUBST_VARS.libdirs=	_OPSYS_LIB_DIRS

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/girepository
# For Darwin
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/girepository

# Disable cache to keep fake homedir clean
MAKE_ENV+=	GI_SCANNER_DISABLE_CACHE=yes

BUILDLINK_API_DEPENDS.glib2+= glib2>=2.58.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libffi+= libffi>=3.0.0
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
