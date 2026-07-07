# $NetBSD: Makefile,v 1.18 2026/07/07 08:47:34 adam Exp $

DISTNAME=	pytest_rerunfailures-16.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pytest_/test-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-rerunfailures/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-rerunfailures
COMMENT=	Pytest plugin to re-run tests to eliminate flaky failures
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-packaging>=17.1:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-test>=8.2.3:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
