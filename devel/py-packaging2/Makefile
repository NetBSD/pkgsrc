# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:19 wiz Exp $

DISTNAME=	packaging-20.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/packaging/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/packaging
COMMENT=	Core utilities for Python packages (Python 2.x version)
LICENSE=	modified-bsd OR apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend

PYTHON_VERSIONS_ACCEPTED=	27

PYTHON_VERSIONED_DEPENDENCIES=	test:test pyparsing

USE_LANGUAGES=	# none

# needs 'make install' before
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
