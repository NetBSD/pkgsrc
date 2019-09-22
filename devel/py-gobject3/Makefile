# $NetBSD: Makefile,v 1.36 2019/09/22 17:52:41 prlw1 Exp $

.include "Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//:S/-/3-/}
EGG_NAME=	${DISTNAME:S/pygobject/PyGObject/}

COMMENT=	Python bindings for glib2 gobject

MESON_ARGS+=	-Dpython=${PYTHONBIN:Q}
MESON_ARGS+=	-Dtests=false
TEST_TARGET=	check

# XXX shouldn't be necessary with -Dinstall-common=false
post-install:
	${RM} \
	${DESTDIR}${PREFIX}/include/pygobject-3.0/pygobject.h \
	${DESTDIR}${PREFIX}/lib/pkgconfig/pygobject-3.0.pc

.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../devel/py-meson/build.mk"
# https://bugzilla.gnome.org/show_bug.cgi?id=685094
# https://bugzilla.gnome.org/show_bug.cgi?id=707196
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
