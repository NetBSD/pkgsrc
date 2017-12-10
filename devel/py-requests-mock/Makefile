# $NetBSD: Makefile,v 1.3 2017/12/10 08:45:40 adam Exp $

DISTNAME=	requests-mock-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-mock/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://requests-mock.readthedocs.org/
COMMENT=	Mock out responses from the requests package
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=1.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-fixtures-[0-9]*:../../devel/py-fixtures
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.1.2:../../textproc/py-sphinx
BUILD_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
