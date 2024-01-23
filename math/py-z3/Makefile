# $NetBSD: Makefile,v 1.7 2024/01/23 20:01:03 adam Exp $

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../math/z3/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
COMMENT=	Efficient SMT solver library

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=46.4.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-importlib-resources-[0-9]*:../../devel/py-importlib-resources

USE_TOOLS+=	cmake ninja
PYSETUPSUBDIR=	src/api/python
WHEEL_NAME=	${DISTNAME:S/z3/z3_solver/}.0

.include "../../mk/bsd.prefs.mk"

post-install:
	# same binary as in math/z3
	${RM} ${DESTDIR}${PREFIX}/bin/z3
.if ${OPSYS} == "Darwin"
	install_name_tool -id ${PREFIX}/${PYSITELIB}/z3/lib/libz3.${PKGVERSION_NOREV:R}.dylib \
	${DESTDIR}${PREFIX}/${PYSITELIB}/z3/lib/libz3.${PKGVERSION_NOREV:R}.dylib
	install_name_tool -id ${PREFIX}/${PYSITELIB}/z3/lib/libz3.dylib \
	${DESTDIR}${PREFIX}/${PYSITELIB}/z3/lib/libz3.dylib
.endif

.include "../../lang/python/wheel.mk"
.include "../../math/z3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
