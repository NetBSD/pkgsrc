# $NetBSD: Makefile,v 1.21 2008/01/18 05:09:41 tnn Exp $
#

DISTNAME=	pycrypto-2.0.1
PKGNAME=	${PYPKGPREFIX}-amkCrypto-2.0.1
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	http://www.amk.ca/files/python/crypto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.amk.ca/python/code/crypto.html
COMMENT=	Cryptographic and hash functions for Python

PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
