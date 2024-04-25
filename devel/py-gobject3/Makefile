# $NetBSD: Makefile,v 1.52 2024/04/25 10:06:10 adam Exp $

.include "Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//:S/-/3-/}

COMMENT=	Python bindings for glib2 gobject

#MESON_ARGS+=	-Dpython=${PYTHONBIN:Q}
#MESON_ARGS+=	-Dtests=false
#TEST_TARGET=	check

TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python>=0.12.1:../../devel/py-meson_python

PYTHON_VERSIONS_INCOMPATIBLE=	27

# Leave for py-gobject3-common:
post-install:
	${RM} ${DESTDIR}${PREFIX}/include/python${PYVERSSUFFIX}/pygobject/pygobject-3.0/pygobject.h

BUILDLINK_API_DEPENDS.glib2=	glib2>=2.48.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection=	gobject-introspection>=1.46.0
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
#.include "../../devel/meson/build.mk"
# https://bugzilla.gnome.org/show_bug.cgi?id=685094
# https://bugzilla.gnome.org/show_bug.cgi?id=707196
.include "../../graphics/py-cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=   cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
