# $NetBSD: Makefile,v 1.38 2025/01/06 11:46:08 adam Exp $

DISTNAME=	numexpr-2.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numexpr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydata/numexpr
COMMENT=	Numerical expression evaluator for NumPy
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	c c++
REPLACE_PYTHON=	numexpr/cpuinfo.py

# needs to be installed first
do-test:
	${PYTHONBIN} -c "import numexpr; numexpr.test()"

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
