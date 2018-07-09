# $NetBSD: Makefile,v 1.1 2018/07/09 02:06:50 minskim Exp $

DISTNAME=	flake8-docstrings-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flake8-docstrings/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://gitlab.com/pycqa/flake8-docstrings
COMMENT=	Extension for flake8 using pydocstyle to check docstrings
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docstyle>=2.1.0:../../devel/py-docstyle
DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
DEPENDS+=	${PYPKGPREFIX}-flake8-polyfill-[0-9]*:../../devel/py-flake8-polyfill

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
