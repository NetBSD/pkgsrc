# $NetBSD: Makefile,v 1.27 2011/10/30 11:46:48 obache Exp $
#

DISTNAME=	pycrypto-2.0.1
PKGNAME=	${PYPKGPREFIX}-amkCrypto-2.0.1
PKGREVISION=	5
CATEGORIES=	security python
MASTER_SITES=	http://www.amk.ca/files/python/crypto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.amk.ca/python/code/crypto.html
COMMENT=	Cryptographic and hash functions for Python

CONFLICTS+=	${PYPKGPREFIX}-crypto-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
