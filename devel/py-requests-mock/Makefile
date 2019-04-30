# $NetBSD: Makefile,v 1.6 2019/04/30 09:34:25 adam Exp $

DISTNAME=	requests-mock-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-mock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://requests-mock.readthedocs.org/
COMMENT=	Mock out responses from the requests package
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=2.3:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
TEST_DEPENDS+=	${PYPKGPREFIX}-fixtures-[0-9]*:../../devel/py-fixtures
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.1.2:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-testrepository>=0.0.18:../../devel/py-testrepository
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
