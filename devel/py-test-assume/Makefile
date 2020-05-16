# $NetBSD: Makefile,v 1.6 2020/05/16 09:15:09 adam Exp $

DISTNAME=	pytest-assume-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-assume/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astraw38/pytest-assume
COMMENT=	Py.test plugin that allows multiple failures per test
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES=	test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
