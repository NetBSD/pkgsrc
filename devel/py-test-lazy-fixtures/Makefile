# $NetBSD: Makefile,v 1.4 2025/01/29 18:20:28 adam Exp $

DISTNAME=	pytest_lazy_fixtures-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-lazy-fixtures/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dev-petrov/pytest-lazy-fixtures
COMMENT=	Allows you to use fixtures in @pytest.mark.parametrize
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-test>=7:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
