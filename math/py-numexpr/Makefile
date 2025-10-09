# $NetBSD: Makefile,v 1.44 2025/10/09 07:57:47 wiz Exp $

DISTNAME=	numexpr-2.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numexpr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydata/numexpr
COMMENT=	Numerical expression evaluator for NumPy
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	c c++
REPLACE_PYTHON=	numexpr/cpuinfo.py

PYTHON_VERSIONS_INCOMPATIBLE=	310

# needs to be installed first
do-test:
	${PYTHONBIN} -c "import numexpr; numexpr.test()"

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
