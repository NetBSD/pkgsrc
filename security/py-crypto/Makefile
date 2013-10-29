# $NetBSD: Makefile,v 1.30 2013/10/29 08:42:14 gls Exp $
#

DISTNAME=	pycrypto-2.6.1
PKGNAME=	${DISTNAME:S/^py/${PYPKGPREFIX}-/}
CATEGORIES=	security python
MASTER_SITES=	http://ftp.dlitz.net/pub/dlitz/crypto/pycrypto/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dlitz.net/software/pycrypto/
COMMENT=	Cryptographic and hash functions for Python
# mostly public domain, but a few bits are:
LICENSE=	python-software-foundation

CONFLICTS+=	${PYPKGPREFIX}-amkCrypto-[0-9]*

PYTHON_VERSIONS_INCLUDE_3X=	yes

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
