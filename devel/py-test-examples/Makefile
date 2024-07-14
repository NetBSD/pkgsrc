# $NetBSD: Makefile,v 1.1 2024/07/14 11:58:24 wiz Exp $

DISTNAME=	pytest_examples-0.0.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest_examples/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/pytest_examples/
COMMENT=	Pytest plugin for testing examples in docstrings and markdown files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-black>=23:../../textproc/py-black
DEPENDS+=	${PYPKGPREFIX}-ruff>=0.5:../../devel/py-ruff
DEPENDS+=	${PYPKGPREFIX}-test>=7:../../devel/py-test

USE_LANGUAGES=	# none

# as of 0.0.12
# 12 failed, 52 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
