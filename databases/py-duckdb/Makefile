# $NetBSD: Makefile,v 1.5 2026/02/01 08:40:05 ryoon Exp $

DISTNAME=	duckdb-1.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=d/duckdb/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://pypi.org/project/duckdb/
COMMENT=	Python module for DuckDB in-process database
LICENSE=	mit

DIST_SUBDIR=	py-duckdb-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build-core-[0-9]*:../../devel/py-scikit-build-core
TOOL_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build

USE_LANGUAGES+=	c c++

USE_TOOLS+=	cmake

PYTHON_VERSIONS_INCOMPATIBLE=	310

WHEEL_ARGS+=	-C skbuild.build-dir=${WRKDIR}/build

post-patch:
	${MKDIR} ${WRKSRC}/build

.include "../../lang/python/wheel.mk"
BUILDLINK_DEPMETHOD.py-pybind11=	full
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
