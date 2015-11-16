# $NetBSD: Makefile,v 1.6 2015/11/16 18:33:51 leot Exp $

DISTNAME=	mitmproxy-0.14.0
CATEGORIES=	net
MASTER_SITES=	http://mitmproxy.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mitmproxy.org/
COMMENT=	Interactive console program for inspecting and editing traffic flows
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Pillow>=2.3.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.2:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-blinker>=1.3:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-certifi>=2015.9.6.2:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-click>=5.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-configargparse>=0.9.3:../../devel/py-configargparse
DEPENDS+=	${PYPKGPREFIX}-construct>=2.5.2:../../devel/py-construct
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
DEPENDS+=	${PYPKGPREFIX}-html2text>=2015.4.14:../../textproc/py-html2text
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.3.6:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-netlib>=0.13:../../net/py-netlib
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=1.5.2:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-pyperclip>=1.5.8:../../x11/py-pyperclip
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.0.2:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-urwid>=1.3:../../devel/py-urwid

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-netlib

REPLACE_PYTHON=	libmproxy/contrib/*.py libmproxy/contrib/wbxml/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
