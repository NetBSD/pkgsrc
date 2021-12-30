# $NetBSD: Makefile,v 1.37 2021/12/30 13:05:40 adam Exp $

DISTNAME=	mitmproxy-7.0.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mitmproxy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://mitmproxy.org/
COMMENT=	Interactive console program for inspecting and editing traffic flows
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=20.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-asgiref>=3.2.10:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-blinker>=1.4:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-brotli>=1.0:../../archivers/py-brotli
DEPENDS+=	${PYPKGPREFIX}-certifi>=2019.9.11:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-click>=7.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.3:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-flask>=1.1.1:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-h2>=4.0:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-hyperframe>=6.0:../../www/py-hyperframe
DEPENDS+=	${PYPKGPREFIX}-kaitaistruct>=0.7:../../devel/py-kaitaistruct
DEPENDS+=	${PYPKGPREFIX}-ldap3>=2.8:../../databases/py-ldap3
DEPENDS+=	${PYPKGPREFIX}-msgpack>=1.0.0:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6.5:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.14:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-publicsuffix2>=2.20190812:../../www/py-publicsuffix2
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.4.2:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-pyperclip>=1.6.0:../../x11/py-pyperclip
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.16:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.3:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.3.0:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-urwid>=2.1.1:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-wsproto>=1.0:../../www/py-wsproto
DEPENDS+=	${PYPKGPREFIX}-zstandard>=0.11.0:../../archivers/py-zstandard

SUBST_CLASSES+=			setuppyversions
SUBST_STAGE.setuppyversions=	pre-configure
SUBST_MESSAGE.setuppyversions=	Avoid too strict version requirements
SUBST_FILES.setuppyversions=	setup.py
SUBST_SED.setuppyversions=	-E -e '/[>=]=/ s/, *(<|!=)[^"]+//g'
SUBST_SED.setuppyversions+=	-E -e '/==[0-9.]+",/ s/==/>=/g'

REPLACE_SH+=	mitmproxy/contrib/kaitaistruct/make.sh

USE_LANGUAGES=			# none

# Only for Python >=3.8
PYTHON_VERSIONS_INCOMPATIBLE=	27 37

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
