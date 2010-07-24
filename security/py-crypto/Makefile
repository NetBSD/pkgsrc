# $NetBSD: Makefile,v 1.19 2010/07/24 12:33:19 gdt Exp $
#

DISTNAME=	pycrypto-2.1.0
PKGREVISION=	3
PKGNAME=	${PYPKGPREFIX}-crypto-2.1.0
CATEGORIES=	security python
MASTER_SITES=	http://ftp.dlitz.net/pub/dlitz/crypto/pycrypto/
# mostly public domain, but a few bits are:
LICENSE=	python-software-foundation

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dlitz.net/software/pycrypto/
COMMENT=	Cryptographic and hash functions for Python

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
