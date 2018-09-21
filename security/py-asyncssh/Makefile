# $NetBSD: Makefile,v 1.10 2018/09/21 10:58:59 adam Exp $

DISTNAME=	asyncssh-1.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asyncssh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://asyncssh.timeheart.net/
COMMENT=	Asynchronous SSHv2 client and server library
LICENSE=	eclipse-license

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=17.0.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.3:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.5:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-gssapi>=1.2.0:../../security/py-gssapi

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
