# $NetBSD: Makefile,v 1.7 2023/03/15 13:06:38 adam Exp $

DISTNAME=	geventhttpclient-2.0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/geventhttpclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gwik/geventhttpclient
COMMENT=	HTTP client library for gevent
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-brotli-[0-9]*:../../archivers/py-brotli
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-gevent>=0.13:../../net/py-gevent
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-certifi

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
