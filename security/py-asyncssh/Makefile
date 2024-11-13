# $NetBSD: Makefile,v 1.47 2024/11/13 10:31:54 adam Exp $

DISTNAME=	asyncssh-2.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asyncssh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asyncssh.readthedocs.io/
COMMENT=	Asynchronous SSHv2 client and server library
LICENSE=	epl-v2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.3:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-gssapi>=1.2.0:../../security/py-gssapi
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
