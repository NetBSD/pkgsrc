# $NetBSD: Makefile,v 1.6 2019/11/13 21:37:28 adam Exp $

DISTNAME=	portend-2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/portend/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/portend
COMMENT=	TCP port monitoring utilities
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-tempora>=1.8:../../time/py-tempora
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.8:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar-[0-9]*:../../devel/py-test-sugar
# missing: pytest-black-multipy

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} test_portend.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
