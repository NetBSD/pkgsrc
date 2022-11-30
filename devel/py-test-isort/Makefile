# $NetBSD: Makefile,v 1.5 2022/11/30 10:31:07 adam Exp $

DISTNAME=	pytest_isort-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-isort/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/moccu/pytest-isort
COMMENT=	Pytest plugin to perform isort checks (import ordering)
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-isort>=4.0:../../devel/py-isort
DEPENDS+=	${PYPKGPREFIX}-test>=5.0:../../devel/py-test

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
