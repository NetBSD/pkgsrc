# $NetBSD: Makefile,v 1.2 2022/01/06 23:30:39 wiz Exp $

DISTNAME=	pytest-mypy-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-mypy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dbader/pytest-mypy
COMMENT=	Mypy static type checker plugin for Pytest
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.0.12:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-test>=6.0.2:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-mypy>=0.782:../../lang/py-mypy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
