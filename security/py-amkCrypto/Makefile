# $NetBSD: Makefile,v 1.9 2003/07/17 22:53:11 grant Exp $
#

DISTNAME=	pycrypto-1.9a4
PKGNAME=	${PYPKGPREFIX}-amkCrypto-1.9a4
CATEGORIES=	security
MASTER_SITES=	http://www.amk.ca/files/python/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.amk.ca/python/code/crypto.html
COMMENT=	cryptographic and hash functions for Python

USE_BUILDLINK2=	yes
PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

.include "../../security/openssl/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
