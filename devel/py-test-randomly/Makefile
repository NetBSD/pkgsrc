# $NetBSD: Makefile,v 1.20 2026/09/03 08:57:53 adam Exp $

DISTNAME=	pytest_randomly-5.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-randomly/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-randomly
COMMENT=	Pytest plugin to randomly order tests and control random.seed
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.12.1:../../devel/py-uv-build
DEPENDS+=	${PYPKGPREFIX}-test>=8:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
