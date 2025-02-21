# $NetBSD: Makefile,v 1.50 2025/02/21 12:02:26 adam Exp $

DISTNAME=	asyncssh-2.20.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asyncssh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asyncssh.readthedocs.io/
COMMENT=	Asynchronous SSHv2 client and server library
LICENSE=	epl-v2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-gssapi>=1.2.0:../../security/py-gssapi
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL bcrypt cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
