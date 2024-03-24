# $NetBSD: Makefile,v 1.48 2024/03/24 20:00:11 leot Exp $

DISTNAME=	mitmproxy-10.2.4
CATEGORIES=	net
MASTER_SITES=	https://downloads.mitmproxy.org/${PKGVERSION_NOREV}/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://mitmproxy.org/
COMMENT=	Interactive TLS-capable intercepting HTTP proxy
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-aioquic>=0.9.24:../../www/py-aioquic
DEPENDS+=	${PYPKGPREFIX}-asgiref>=3.2.10:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-brotli>=1.0:../../archivers/py-brotli
DEPENDS+=	${PYPKGPREFIX}-certifi>=2019.9.11:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-click>=7.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-cryptography>=42.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-flask>=1.1.1:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-h11>=0.11:../../www/py-h11
DEPENDS+=	${PYPKGPREFIX}-h2>=4.1:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-hyperframe>=6.0:../../www/py-hyperframe
DEPENDS+=	${PYPKGPREFIX}-kaitaistruct>=0.10:../../devel/py-kaitaistruct
DEPENDS+=	${PYPKGPREFIX}-ldap3>=2.8:../../databases/py-ldap3
DEPENDS+=	${PYPKGPREFIX}-mitmproxy_rs>=0.5.1:../../net/py-mitmproxy_rs
DEPENDS+=	${PYPKGPREFIX}-msgpack>=1.0.0:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=22.1:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6.5:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.14:../../devel/py-protobuf
DEPENDS+=	${PYPKGPREFIX}-publicsuffix2>=2.20190812:../../www/py-publicsuffix2
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.4.2:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-pyperclip>=1.6.0:../../x11/py-pyperclip
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.16:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.3:../../devel/py-sortedcontainers
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.2:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-urwid>=2.1.1:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-wsproto>=1.0:../../www/py-wsproto
DEPENDS+=	${PYPKGPREFIX}-zstandard>=0.11:../../archivers/py-zstandard

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.3:../../devel/py-typing-extensions
.endif

# Forked urwid-mitmproxy-2.1.2.1 contains patches for Windows. They should be
# not needed in pkgsrc and this spare us some kludges and maintainance due
# forked urwid.
SUBST_CLASSES+=		urwid
SUBST_STAGE.urwid=	pre-configure
SUBST_MESSAGE.urwid=	Use non-forked urwid
SUBST_FILES.urwid=	pyproject.toml
SUBST_SED.urwid+=	-e 's/urwid-mitmproxy/urwid/g'

SUBST_CLASSES+=				pyprojecttomlversions
SUBST_STAGE.pyprojecttomlversions=	pre-configure
SUBST_MESSAGE.pyprojecttomlversions=	Avoid too strict version requirements
SUBST_FILES.pyprojecttomlversions=	pyproject.toml
SUBST_SED.pyprojecttomlversions+=	-E -e '/[>=]=/ s/, *<[0-9.]+(",|;)/\1/g'

REPLACE_SH+=	mitmproxy/contrib/kaitaistruct/make.sh

USE_LANGUAGES=			# none

# Only for Python >=3.10
PYTHON_VERSIONS_INCOMPATIBLE=	27 38 39

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
