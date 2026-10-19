# $NetBSD: Makefile,v 1.23 2026/10/19 15:55:15 adam Exp $

DISTNAME=	geventhttpclient-2.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/geventhttpclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gwik/geventhttpclient
COMMENT=	HTTP client library for gevent
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-brotli>=0:../../archivers/py-brotli
DEPENDS+=	${PYPKGPREFIX}-certifi>=0:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-gevent>=25.9:../../net/py-gevent
TEST_DEPENDS+=	${PYPKGPREFIX}-dpkt>=0:../../net/py-dpkt
TEST_DEPENDS+=	${PYPKGPREFIX}-httplib2>=0:../../www/py-httplib2
TEST_DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures>=0:../../devel/py-test-rerunfailures

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
