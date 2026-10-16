# $NetBSD: Makefile,v 1.62 2026/10/16 19:44:11 adam Exp $

DISTNAME=	asyncssh-2.24.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asyncssh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asyncssh.readthedocs.io/
COMMENT=	Asynchronous SSHv2 client and server library
LICENSE=	epl-v2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cryptography>=48.0.1:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.0:../../devel/py-typing-extensions
# pyOpenSSL
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=23.0.0:../../security/py-OpenSSL
# bcrypt
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.3:../../security/py-bcrypt
# gssapi
DEPENDS+=	${PYPKGPREFIX}-gssapi>=1.2.0:../../security/py-gssapi

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
