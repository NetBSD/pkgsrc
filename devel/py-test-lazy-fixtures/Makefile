# $NetBSD: Makefile,v 1.9 2025/08/19 10:46:41 adam Exp $

DISTNAME=	pytest_lazy_fixtures-1.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-lazy-fixtures/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dev-petrov/pytest-lazy-fixtures
COMMENT=	Allows you to use fixtures in @pytest.mark.parametrize
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-test>=7:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
