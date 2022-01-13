# $NetBSD: Makefile,v 1.9 2022/01/13 19:31:21 wiz Exp $

DISTNAME=	portend-2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/portend/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/portend
COMMENT=	TCP port monitoring utilities
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-tempora>=1.8:../../time/py-tempora
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar-[0-9]*:../../devel/py-test-sugar
# missing: pytest-black-multipy

PYTHON_VERSIONED_DEPENDENCIES=	test:test setuptools_scm:build

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} test_portend.py

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
