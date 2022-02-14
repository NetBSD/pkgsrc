# $NetBSD: Makefile,v 1.1 2022/02/14 08:52:02 adam Exp $

DISTNAME=	pytest-lazy-fixture-0.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-lazy-fixture/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tvorog/pytest-lazy-fixture
COMMENT=	Helps to use fixtures in pytest.mark.parametrize
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	test

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
