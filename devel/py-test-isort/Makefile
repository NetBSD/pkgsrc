# $NetBSD: Makefile,v 1.2 2020/05/16 14:05:15 adam Exp $

DISTNAME=	pytest-isort-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-isort/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/moccu/pytest-isort/
COMMENT=	Pytest plugin to perform isort checks (import ordering)
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-isort>=3.9.6:../../devel/py-isort
DEPENDS+=	${PYPKGPREFIX}-test-cache>=1.0:../../devel/py-test-cache

PYTHON_VERSIONED_DEPENDENCIES=	test

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
