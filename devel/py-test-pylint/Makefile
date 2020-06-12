# $NetBSD: Makefile,v 1.3 2020/06/12 06:31:08 adam Exp $

DISTNAME=	pytest-pylint-0.17.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-pylint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/carsongee/pytest-pylint
COMMENT=	Pytest plugin to check source code with Pylint
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pylint>=2.3.0:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-test>=5.4:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-toml>=0.7.1:../../textproc/py-toml
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-pylint

# test are not included
do-test:
	${DO_NADA}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
