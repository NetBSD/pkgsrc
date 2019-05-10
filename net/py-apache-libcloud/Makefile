# $NetBSD: Makefile,v 1.13 2019/05/10 14:58:37 mef Exp $

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
	${RM} -f ${WRKSRC}/libcloud/compute/drivers/azure.py.orig
	${RM} -f ${WRKSRC}/build/lib/libcloud/compute/drivers/azure.py.orig
	${RM} -f ${WRKSRC}/build/lib/libcloud/compute/drivers/azure.py.rej

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
