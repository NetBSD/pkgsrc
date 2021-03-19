# $NetBSD: Makefile,v 1.3 2021/03/19 07:35:04 adam Exp $

DISTNAME=	flake8-docstrings-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flake8-docstrings/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://gitlab.com/pycqa/flake8-docstrings
COMMENT=	Extension for flake8 using pydocstyle to check docstrings
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docstyle>=2.1.0:../../devel/py-docstyle
DEPENDS+=	${PYPKGPREFIX}-flake8>=3.0.0:../../devel/py-flake8

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
