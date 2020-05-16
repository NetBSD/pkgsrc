# $NetBSD: Makefile,v 1.5 2020/05/16 17:38:40 adam Exp $

DISTNAME=	pytest-virtualenv-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-virtualenv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/manahl/pytest-plugins
COMMENT=	Virtualenv fixture for py.test
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-test-fixture-config-[0-9]*:../../devel/py-test-fixture-config
DEPENDS+=	${PYPKGPREFIX}-test-shutil-[0-9]*:../../devel/py-test-shutil
DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

PYTHON_VERSIONED_DEPENDENCIES=	test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
