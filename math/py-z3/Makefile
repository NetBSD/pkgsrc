# $NetBSD: Makefile,v 1.6 2023/05/16 19:23:05 wiz Exp $

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../math/z3/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
COMMENT=	Efficient SMT solver library

USE_TOOLS+=	cmake ninja
PYSETUPSUBDIR=	src/api/python
EGG_NAME=	${DISTNAME:S/z3/z3_solver/}.0

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

.include "../../lang/python/egg.mk"
.include "../../math/z3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
