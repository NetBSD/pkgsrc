# $NetBSD: Makefile,v 1.1 2025/06/15 13:31:39 ryoon Exp $

.include "../../databases/duckdb/Makefile.common"
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://pypi.org/project/duckdb/
COMMENT=	Python module for DuckDB in-process database
LICENSE=	mit

USE_LANGUAGES+=	c++

BUILD_DIRS=	tools/pythonpkg
PYSETUPSUBDIR=	${BUILD_DIRS}

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/duckdb_build
	${RM} -f ${DESTDIR}${PREFIX}/*.list

.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
