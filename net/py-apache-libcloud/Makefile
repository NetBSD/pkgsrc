# $NetBSD: Makefile,v 1.21 2026/02/16 12:28:56 adam Exp $

DISTNAME=	apache_libcloud-3.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/apache-libcloud/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://libcloud.apache.org/
COMMENT=	Python library for interacting with cloud service providers
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests>=2.26.0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock-[0-9]*:../../devel/py-requests-mock

USE_LANGUAGES=	# none

pre-test:
	${LN} -f -s ${WRKSRC}/libcloud/test/secrets.py-dist ${WRKSRC}/libcloud/test/secrets.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
