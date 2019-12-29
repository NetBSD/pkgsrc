# $NetBSD: Makefile,v 1.1 2019/12/29 04:44:58 ryoon Exp $

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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
