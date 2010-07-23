# $NetBSD: Makefile,v 1.18 2010/07/23 23:12:36 gdt Exp $
#

DISTNAME=	pycrypto-2.1.0
PKGREVISION=	2
PKGNAME=	${PYPKGPREFIX}-crypto-2.1.0
CATEGORIES=	security python
MASTER_SITES=	http://ftp.dlitz.net/pub/dlitz/crypto/pycrypto/
# mostly public domain, but a few bits are:
LICENSE=	python-software-foundation

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dlitz.net/software/pycrypto/
COMMENT=	Cryptographic and hash functions for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PY_NO_EGG=	no
EGG_NAME?=	${DISTNAME}
PLIST_SUBST+=	EGG_FILE=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
