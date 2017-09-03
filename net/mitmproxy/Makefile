# $NetBSD: Makefile,v 1.18 2017/09/03 08:53:12 wiz Exp $

DISTNAME=	mitmproxy-2.0.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mitmproxy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mitmproxy.org/
COMMENT=	Interactive console program for inspecting and editing traffic flows
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=16.0.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-Pillow>=3.2:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.9:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-blinker>=1.4:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-brotlipy>=0.5.1:../../archivers/py-brotlipy
DEPENDS+=	${PYPKGPREFIX}-certifi>=2015.11.20.1:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-click>=6.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-configargparse>=0.10.0:../../devel/py-configargparse
DEPENDS+=	${PYPKGPREFIX}-construct>=2.5.2:../../devel/py-construct
DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.3:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-cssutils>=1.0.1:../../textproc/py-cssutils
DEPENDS+=	${PYPKGPREFIX}-flask>=0.10.1:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-h2>=2.5.1:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-hpack>=2.1.0:../../net/py-hpack
DEPENDS+=	${PYPKGPREFIX}-html2text>=2016.1.8:../../textproc/py-html2text
DEPENDS+=	${PYPKGPREFIX}-hyperframe>=4.0.1:../../www/py-hyperframe
DEPENDS+=	${PYPKGPREFIX}-jsbeautifier>=1.6.3:../../textproc/py-jsbeautifier
DEPENDS+=	${PYPKGPREFIX}-kaitaistruct>=0.6:../../devel/py-kaitaistruct
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.5.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6.5:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.1.3:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-pyperclip>=1.5.22:../../x11/py-pyperclip
DEPENDS+=	${PYPKGPREFIX}-requests>=2.9.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.13.2:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-requests>=2.9.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=1.5.4:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.3.0:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-urwid>=1.3.1:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-watchdog>=0.8.3:../../sysutils/py-watchdog

USE_LANGUAGES=			# none
PYTHON_VERSIONS_INCOMPATIBLE=	27 34

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
