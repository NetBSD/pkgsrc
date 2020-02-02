# $NetBSD: Makefile,v 1.2 2020/02/02 00:17:23 gutteridge Exp $

DISTNAME=	PyChromecast-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyChromecast/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/balloob/pychromecast
COMMENT=	Python module to talk to Google Chromecast
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.0.0:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-zeroconf>=0.17.7:../../net/py-zeroconf
#DEPENDS+=	# TODO: casttube

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
