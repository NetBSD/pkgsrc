# $NetBSD: Makefile,v 1.35 2023/01/11 12:04:08 adam Exp $

DISTNAME=	asyncssh-2.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asyncssh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asyncssh.readthedocs.io/
COMMENT=	Asynchronous SSHv2 client and server library
LICENSE=	eclipse-license

DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.3:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-gssapi>=1.2.0:../../security/py-gssapi
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.6:../../devel/py-typing-extensions

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
