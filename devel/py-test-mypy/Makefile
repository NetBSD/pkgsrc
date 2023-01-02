# $NetBSD: Makefile,v 1.7 2023/01/02 13:06:07 adam Exp $

DISTNAME=	pytest-mypy-0.10.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-mypy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dbader/pytest-mypy
COMMENT=	Mypy static type checker plugin for Pytest
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.5:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.0:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-test>=6.2:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-mypy>=0.900:../../lang/py-mypy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
