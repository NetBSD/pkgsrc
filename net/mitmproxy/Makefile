# $NetBSD: Makefile,v 1.3 2014/05/09 07:37:14 wiz Exp $

DISTNAME=	mitmproxy-0.9
CATEGORIES=	net
MASTER_SITES=	http://mitmproxy.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mitmproxy.org/
COMMENT=	Interactive console program for inspecting and editing traffic flows
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.2:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-flask>=0.9:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-imaging>=1.1:../../graphics/py-imaging
DEPENDS+=	${PYPKGPREFIX}-lxml>=2.3:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-netlib>=0.9:../../net/py-netlib
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.13:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-urwid>=1.1:../../devel/py-urwid

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-imaging, py-netlib

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
