# $NetBSD: Makefile,v 1.18 2005/10/25 17:07:27 drochner Exp $
#

DISTNAME=	pycrypto-2.0.1
PKGNAME=	${PYPKGPREFIX}-amkCrypto-2.0.1
CATEGORIES=	security python
MASTER_SITES=	http://www.amk.ca/files/python/crypto/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.amk.ca/python/code/crypto.html
COMMENT=	Cryptographic and hash functions for Python

PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
