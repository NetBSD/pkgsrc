# $NetBSD: Makefile,v 1.1 2026/08/03 17:47:34 wiz Exp $

DISTNAME=	pytest_factoryboy-2.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest_factoryboy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-factoryboy
COMMENT=	Factory Boy support for pytest
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-test>=7:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-inflection>=0:../../textproc/py-inflection
DEPENDS+=	${PYPKGPREFIX}-factory_boy>=2.10.0:../../devel/py-factory_boy
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
