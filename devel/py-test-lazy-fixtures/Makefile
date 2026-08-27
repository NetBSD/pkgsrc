# $NetBSD: Makefile,v 1.11 2026/08/27 05:48:12 adam Exp $

DISTNAME=	pytest_lazy_fixtures-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-lazy-fixtures/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dev-petrov/pytest-lazy-fixtures
COMMENT=	Allows you to use fixtures in @pytest.mark.parametrize
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-test>=7:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
