# $NetBSD: Makefile,v 1.8 2023/05/03 20:00:36 adam Exp $

DISTNAME=	flake8_docstrings-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flake8-docstrings/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pycqa/flake8-docstrings
COMMENT=	Extension for flake8 using pydocstyle to check docstrings
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docstyle>=2.1:../../devel/py-docstyle
DEPENDS+=	${PYPKGPREFIX}-flake8>=3:../../devel/py-flake8

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
