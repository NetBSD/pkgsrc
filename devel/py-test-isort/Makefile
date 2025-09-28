# $NetBSD: Makefile,v 1.7 2025/09/28 19:41:10 wiz Exp $

DISTNAME=	pytest_isort-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-isort/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/moccu/pytest-isort
COMMENT=	Pytest plugin to perform isort checks (import ordering)
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-isort>=4.0:../../devel/py-isort
DEPENDS+=	${PYPKGPREFIX}-test>=5.0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
