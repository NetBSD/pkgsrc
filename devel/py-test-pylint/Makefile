# $NetBSD: Makefile,v 1.2 2019/11/15 09:57:52 adam Exp $

DISTNAME=	pytest-pylint-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-pylint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/carsongee/pytest-pylint
COMMENT=	Pytest plugin to check source code with Pylint
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pylint>=1.4.5:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-test>=2.7:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-pylint

# test are not included
do-test:
	${DO_NADA}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
