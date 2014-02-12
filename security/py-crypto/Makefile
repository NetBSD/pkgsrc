# $NetBSD: Makefile,v 1.35 2014/02/12 23:18:36 tron Exp $

DISTNAME=	pycrypto-2.6.1
PKGNAME=	${DISTNAME:S/^py/${PYPKGPREFIX}-/}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	http://ftp.dlitz.net/pub/dlitz/crypto/pycrypto/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.dlitz.net/software/pycrypto/
COMMENT=	Cryptographic and hash functions for Python
# mostly public domain, but a few bits are:
LICENSE=	python-software-foundation

CONFLICTS+=	${PYPKGPREFIX}-amkCrypto-[0-9]*
SUPERSEDES+=	${PYPKGPREFIX}-amkCrypto-[0-9]*

GNU_CONFIGURE=	yes

do-test:
	${RUN}cd ${WRKSRC};${SETENV} ${TEST_ENV} ${PYTHONBIN} ${PYSETUP} test

PLIST_VARS+=	py2x
.include "../../lang/python/pyversion.mk"
.if empty(PYPKGPREFIX:Mpy3?)
PLIST.py2x=	yes
.endif

CFLAGS.SunOS+=	-std=c99 -D_XOPEN_SOURCE=600

BUILDLINK_API_DEPENDS.gmp+=	gmp>=5.0
.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
