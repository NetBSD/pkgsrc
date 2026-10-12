# $NetBSD: Makefile,v 1.98 2026/10/12 21:57:51 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}

COMMENT=	Python bindings for cairo

.include "Makefile.common"

TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python-[0-9]*:../../devel/py-meson_python
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_TOOLS+=	pkg-config

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

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.13.1
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/py-cairo-shared/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
