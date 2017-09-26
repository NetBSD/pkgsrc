# $NetBSD: Makefile,v 1.10 2017/09/26 17:21:10 adam Exp $

DISTNAME=	apache-libcloud-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/apache-libcloud/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://libcloud.apache.org/
COMMENT=	Python library for interacting with cloud service providers
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
BUILD_DEPENDS+=	${PYPKGPREFIX}-requests-mock-[0-9]*:../../devel/py-requests-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
