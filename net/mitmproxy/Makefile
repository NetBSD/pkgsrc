# $NetBSD: Makefile,v 1.10 2016/02/16 13:54:00 leot Exp $

DISTNAME=	mitmproxy-0.16
CATEGORIES=	net
MASTER_SITES=	http://mitmproxy.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mitmproxy.org/
COMMENT=	Interactive console program for inspecting and editing traffic flows
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Pillow>=3.1:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-blinker>=1.4:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-certifi>=2015.9.6.2:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-click>=6.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-configargparse>=0.10.0:../../devel/py-configargparse
DEPENDS+=	${PYPKGPREFIX}-construct>=2.5.2:../../devel/py-construct
DEPENDS+=	${PYPKGPREFIX}-enum34>=1.0.4:../../devel/py-enum34
DEPENDS+=	${PYPKGPREFIX}-h2>=2.1.0:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-html2text>=2015.11.4:../../textproc/py-html2text
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.5.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-netlib>=0.15:../../net/py-netlib
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.1:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-pyperclip>=1.5.22:../../x11/py-pyperclip
DEPENDS+=	${PYPKGPREFIX}-six>=1.10:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.3.0:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-urwid>=1.3.1:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-watchdog>=0.8.3:../../sysutils/py-watchdog

USE_LANGUAGES=			# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-netlib

REPLACE_PYTHON=	libmproxy/contrib/*.py libmproxy/contrib/wbxml/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
