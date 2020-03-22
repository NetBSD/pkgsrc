# $NetBSD: Makefile,v 1.40 2020/03/22 18:36:17 wiz Exp $

.include "Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//:S/-/3-/}
EGG_NAME=	${DISTNAME:S/pygobject/PyGObject/}

COMMENT=	Python bindings for glib2 gobject

MESON_ARGS+=	-Dpython=${PYTHONBIN:Q}
MESON_ARGS+=	-Dtests=false
TEST_TARGET=	check

# Leave for py-gobject3-common:
post-install:
	${RM} \
	${DESTDIR}${PREFIX}/include/pygobject-3.0/pygobject.h \
	${DESTDIR}${PREFIX}/lib/pkgconfig/pygobject-3.0.pc

BUILDLINK_API_DEPENDS.glib2=	glib2>=2.48.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection=	gobject-introspection>=1.46.0
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../devel/meson/build.mk"
# https://bugzilla.gnome.org/show_bug.cgi?id=685094
# https://bugzilla.gnome.org/show_bug.cgi?id=707196
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
