# $NetBSD: Makefile,v 1.9 2024/03/17 17:42:08 adam Exp $

DISTNAME=	pytest-rerunfailures-14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-rerunfailures/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-rerunfailures
COMMENT=	Pytest plugin to re-run tests to eliminate flaky failures
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=40:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-packaging>=17.1:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-test>=7.2:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
