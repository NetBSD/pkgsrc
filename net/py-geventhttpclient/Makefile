# $NetBSD: Makefile,v 1.13 2025/01/08 14:32:19 adam Exp $

DISTNAME=	geventhttpclient-2.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/geventhttpclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gwik/geventhttpclient
COMMENT=	HTTP client library for gevent
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-brotli-[0-9]*:../../archivers/py-brotli
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-gevent>=0.13:../../net/py-gevent
DEPENDS+=	${PYPKGPREFIX}-urllib3-[0-9]*:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-dpkt-[0-9]*:../../net/py-dpkt

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
