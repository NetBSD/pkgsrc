# $NetBSD: Makefile,v 1.8 2023/10/06 12:43:24 adam Exp $

DISTNAME=	pytest-pylint-0.21.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-pylint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/carsongee/pytest-pylint
COMMENT=	Pytest plugin to check source code with Pylint
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pylint>=2.15.0:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-test>=7.0:../../devel/py-test
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
.endif

# test are not included
do-test:
	${DO_NADA}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
