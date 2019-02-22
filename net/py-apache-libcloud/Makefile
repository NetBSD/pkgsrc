# $NetBSD: Makefile,v 1.12 2019/02/22 08:59:49 adam Exp $

DISTNAME=	apache-libcloud-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/apache-libcloud/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://libcloud.apache.org/
COMMENT=	Python library for interacting with cloud service providers
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock-[0-9]*:../../devel/py-requests-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

pre-install:
	${RM} ${WRKSRC}/libcloud/compute/drivers/azure.py.orig
	${RM} ${WRKSRC}/build/lib/libcloud/compute/drivers/azure.py.orig

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
