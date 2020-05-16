# $NetBSD: Makefile,v 1.10 2020/05/16 17:38:40 adam Exp $

DISTNAME=	pytest-timeout-1.3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-timeout/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-timeout
COMMENT=	Py.test plugin to abort hanging tests
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES=	test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
