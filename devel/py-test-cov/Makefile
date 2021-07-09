# $NetBSD: Makefile,v 1.18 2021/07/09 20:00:30 adam Exp $

DISTNAME=	pytest-cov-2.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-cov/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-cov
COMMENT=	Pytest plugin for measuring coverage
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-coverage>=5.2.1:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml

PYTHON_VERSIONED_DEPENDENCIES=	test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
