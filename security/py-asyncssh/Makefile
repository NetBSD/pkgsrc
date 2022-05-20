# $NetBSD: Makefile,v 1.30 2022/05/20 12:09:48 adam Exp $

DISTNAME=	asyncssh-2.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asyncssh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asyncssh.readthedocs.io/
COMMENT=	Asynchronous SSHv2 client and server library
LICENSE=	eclipse-license

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=17.0.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.3:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.8:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-gssapi>=1.2.0:../../security/py-gssapi
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.6:../../devel/py-typing-extensions

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
