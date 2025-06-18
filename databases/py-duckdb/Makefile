# $NetBSD: Makefile,v 1.2 2025/06/18 08:14:36 wiz Exp $

.include "../../databases/duckdb/Makefile.common"
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://pypi.org/project/duckdb/
COMMENT=	Python module for DuckDB in-process database
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-pybind11>=2.6.0:../../devel/py-pybind11

USE_LANGUAGES+=	c++

BUILD_DIRS=	tools/pythonpkg
PYSETUPSUBDIR=	${BUILD_DIRS}

# as of 1.3.0
# 95 skipped, 648 deselected, 65 errors

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/duckdb_build
	${RM} -f ${DESTDIR}${PREFIX}/*.list

.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
