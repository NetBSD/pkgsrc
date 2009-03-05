# $NetBSD: Makefile,v 1.24 2009/03/05 18:51:31 joerg Exp $
#

DISTNAME=	pycrypto-2.0.1
PKGNAME=	${PYPKGPREFIX}-amkCrypto-2.0.1
PKGREVISION=	3
CATEGORIES=	security python
MASTER_SITES=	http://www.amk.ca/files/python/crypto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.amk.ca/python/code/crypto.html
COMMENT=	Cryptographic and hash functions for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
