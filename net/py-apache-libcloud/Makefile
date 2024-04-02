# $NetBSD: Makefile,v 1.18 2024/04/02 19:32:39 adam Exp $

DISTNAME=	apache-libcloud-3.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/apache-libcloud/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://libcloud.apache.org/
COMMENT=	Python library for interacting with cloud service providers
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=66.1:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.37.1:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-requests>=2.26.0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock-[0-9]*:../../devel/py-requests-mock

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-test:
	${LN} -f -s ${WRKSRC}/libcloud/test/secrets.py-dist ${WRKSRC}/libcloud/test/secrets.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
