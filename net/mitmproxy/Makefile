# $NetBSD: Makefile,v 1.4 2015/03/09 09:18:03 wiz Exp $

DISTNAME=	mitmproxy-0.11.3
CATEGORIES=	net
MASTER_SITES=	http://mitmproxy.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mitmproxy.org/
COMMENT=	Interactive console program for inspecting and editing traffic flows
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.2:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.0.2:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-Pillow>=2.3.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.3.6:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-netlib>=0.11:../../net/py-netlib
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.14:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-urwid>=1.1:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-configargparse>=0.9.3:../../devel/py-configargparse

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-netlib

REPLACE_PYTHON=	libmproxy/contrib/*.py libmproxy/contrib/wbxml/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
