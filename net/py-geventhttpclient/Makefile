# $NetBSD: Makefile,v 1.1 2017/07/14 10:44:59 adam Exp $

DISTNAME=	geventhttpclient-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/geventhttpclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gwik/geventhttpclient
COMMENT=	HTTP client library for gevent
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-gevent>=0.13:../../net/py-gevent
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

post-extract:
	${RM} -f -r ${WRKSRC}/src/geventhttpclient/tests/__pycache__

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
