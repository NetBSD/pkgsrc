# $NetBSD: Makefile,v 1.14 2021/11/09 20:35:14 wiz Exp $

DISTNAME=	packaging-21.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/packaging/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/packaging
COMMENT=	Core utilities for Python packages
LICENSE=	modified-bsd OR apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_VERSIONED_DEPENDENCIES=	test:test pyparsing

USE_LANGUAGES=	# none

# as of 21.2:
# 1 failed, 29293 passed, 1 skipped, 1 xfailed, 15439 warnings
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
