# $NetBSD: Makefile,v 1.89 2023/11/02 13:23:48 wiz Exp $

DISTNAME=	gobject-introspection-1.78.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gobject-introspection/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gi.readthedocs.io/en/latest/
COMMENT=	GObject Introspection
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_TOOLS+=	pkg-config flex bison

MESON_ARGS+=	-Dpython=${PYTHONBIN}
MESON_ARGS+=	-Ddoctool=disabled

PKGCONFIG_OVERRIDE+=	output/meson-private/gobject-introspection-1.0.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/gobject-introspection-no-export-1.0.pc

PKGCONFIG_OVERRIDE_STAGE=	post-build

SUBST_CLASSES+=		timet
SUBST_STAGE.timet=	pre-configure
SUBST_FILES.timet=	giscanner/ast.py
SUBST_FILES.timet+=	tests/scanner/Regress-1.0-expected.gir
.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_PLATFORM:MNetBSD-5.99.*} || ${MACHINE_PLATFORM:MNetBSD-[6-9].*} || ${MACHINE_PLATFORM:MMirBSD-*}
SUBST_SED.timet=	-e 's,@TIMET_TYPENAME@,TYPE_INT64,g'
SUBST_SED.timet+=	-e 's,@TIMET_CTYPE@,gint64,g'
.else
SUBST_SED.timet=	-e 's,@TIMET_TYPENAME@,TYPE_LONG,g'
SUBST_SED.timet+=	-e 's,@TIMET_CTYPE@,glong,g'
.endif

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

# remove after patch-giscanner_doctemplates_*_meson.build are removed,
# probably in 1.72.0
post-install:
	${FIND} ${DESTDIR}${PREFIX} -name \*.orig -exec rm {} \;

BUILDLINK_API_DEPENDS.glib2+= glib2>=2.78.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libffi+= libffi>=3.0.0
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
