# $NetBSD: Makefile,v 1.14 2004/04/27 05:44:22 snj Exp $
#

DISTNAME=	pycrypto-1.9a6
PKGNAME=	${PYPKGPREFIX}-amkCrypto-1.9a6
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.amk.ca/files/python/crypto/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.amk.ca/python/code/crypto.html
COMMENT=	Cryptographic and hash functions for Python

USE_BUILDLINK3=	yes
PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
