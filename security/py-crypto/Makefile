# $NetBSD: Makefile,v 1.16 2010/07/22 19:34:11 gdt Exp $
#

DISTNAME=	pycrypto-2.1.0
PKGNAME=	${PYPKGPREFIX}-crypto-2.1.0
CATEGORIES=	security python
MASTER_SITES=	http://ftp.dlitz.net/pub/dlitz/crypto/pycrypto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dlitz.net/software/pycrypto/
COMMENT=	Cryptographic and hash functions for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
