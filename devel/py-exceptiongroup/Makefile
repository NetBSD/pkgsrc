# $NetBSD: Makefile,v 1.1 2022/07/03 12:36:06 wiz Exp $

DISTNAME=	exceptiongroup-1.0.0rc8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/exceptiongroup/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/exceptiongroup/
COMMENT=	Backport of PEP 654 (exception groups)
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flit_scm-[0-9]*:../../devel/py-flit_scm
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# 'tests' directory not in pypi distfile
#do-test:
#	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
