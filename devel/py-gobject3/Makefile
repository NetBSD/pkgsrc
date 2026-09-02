# $NetBSD: Makefile,v 1.62 2026/09/02 19:01:43 wiz Exp $

.include "Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//:S/-/3-/}
PKGREVISION=	3

COMMENT=	Python bindings for glib2 gobject

TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python>=0.12.1:../../devel/py-meson_python
DEPENDS+=	glib2-introspection-[0-9]*:../../devel/glib2-introspection
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

# Installed by py-gobject3-common:
post-install:
	${RM} ${DESTDIR}${PREFIX}/include/python${PYVERSSUFFIX}/pygobject/pygobject-3.0/pygobject.h
	${RM} ${DESTDIR}${PREFIX}/include/python${PYVERSSUFFIX}/pygobject/pygobject-3.0/pygobject-types.h

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.88.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.46.0
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
# https://bugzilla.gnome.org/show_bug.cgi?id=685094
# https://bugzilla.gnome.org/show_bug.cgi?id=707196
.include "../../graphics/py-cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=   cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"

# = 28 failed, 1481 passed, 201 skipped, 2 deselected, 6 xfailed, 720 warnings in 16.58s =
MESON_TESTBUILDDIR=	${WRKDIR}/testbuild

do-test:
	${RUN} printf '[binaries]\npython = %s\n' "'${PYTHONBIN}'" > ${WRKDIR}/.meson_test_native
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	    meson setup \
	    --prefix ${PREFIX} \
	    --wrap-mode=nodownload \
	    --native-file ${WRKDIR}/.meson_test_native \
	    -Dtests=true \
	    -Dwheel=false \
	    ${MESON_TESTBUILDDIR}
	${RUN} ${SETENV} ${MAKE_ENV} \
	    ninja -C ${MESON_TESTBUILDDIR}
	${RUN} cd ${WRKSRC} && ${SETENV} ${TEST_ENV} \
	    meson test -C ${MESON_TESTBUILDDIR} --no-rebuild --timeout 600
#	    meson test -C ${MESON_TESTBUILDDIR} --no-rebuild --timeout 600 \
#	    --test-args="-k 'not (test_pytest_capture_error_in_closure or test_io_add_watch_pyfile)'"

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
