# $NetBSD: Makefile,v 1.51 2025/02/06 13:22:10 adam Exp $

DISTNAME=	mitmproxy-11.1.2
CATEGORIES=	net
MASTER_SITES=	https://downloads.mitmproxy.org/${PKGVERSION_NOREV}/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://mitmproxy.org/
COMMENT=	Interactive TLS-capable intercepting HTTP proxy
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aioquic>=1.1.0:../../www/py-aioquic
DEPENDS+=	${PYPKGPREFIX}-asgiref>=3.2.10:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-brotli>=1.0:../../archivers/py-brotli
DEPENDS+=	${PYPKGPREFIX}-certifi>=2019.9.11:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-cryptography>=42.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-flask>=3.0:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-h11>=0.11:../../www/py-h11
DEPENDS+=	${PYPKGPREFIX}-h2>=4.1:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-hyperframe>=6.0:../../www/py-hyperframe
DEPENDS+=	${PYPKGPREFIX}-kaitaistruct>=0.10:../../devel/py-kaitaistruct
DEPENDS+=	${PYPKGPREFIX}-ldap3>=2.8:../../databases/py-ldap3
DEPENDS+=	${PYPKGPREFIX}-mitmproxy_rs>=0.11.2:../../net/py-mitmproxy_rs
DEPENDS+=	${PYPKGPREFIX}-msgpack>=1.0.0:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=22.1:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6.5:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-publicsuffix2>=2.20190812:../../www/py-publicsuffix2
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.4.2:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-pyperclip>=1.9.0:../../x11/py-pyperclip
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.16:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.3:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.2:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-urwid>=2.6.14:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-wsproto>=1.0:../../www/py-wsproto
DEPENDS+=	${PYPKGPREFIX}-zstandard>=0.15:../../archivers/py-zstandard
# urwid[trio]
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>0:../../devel/py-exceptiongroup
DEPENDS+=	${PYPKGPREFIX}-trio>=0.22.0:../../devel/py-trio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310 311

SUBST_CLASSES+=				pyprojecttomlversions
SUBST_STAGE.pyprojecttomlversions=	pre-configure
SUBST_MESSAGE.pyprojecttomlversions=	Avoid too strict version requirements
SUBST_FILES.pyprojecttomlversions=	pyproject.toml
SUBST_SED.pyprojecttomlversions+=	-E -e '/[>=]=/ s/, *<[0-9.]+(",|;)/\1/g'

REPLACE_SH+=	mitmproxy/contrib/kaitaistruct/make.sh

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
