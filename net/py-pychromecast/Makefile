# $NetBSD: Makefile,v 1.4 2025/07/05 11:44:10 wiz Exp $

DISTNAME=	PyChromecast-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
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

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
