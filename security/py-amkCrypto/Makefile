# $NetBSD: Makefile,v 1.12 2003/11/12 03:39:43 jschauma Exp $
#

DISTNAME=	pycrypto-1.9a6
PKGNAME=	${PYPKGPREFIX}-amkCrypto-1.9a6
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.amk.ca/files/python/crypto/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.amk.ca/python/code/crypto.html
COMMENT=	Cryptographic and hash functions for Python

USE_BUILDLINK2=	yes
PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

.include "../../security/openssl/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
