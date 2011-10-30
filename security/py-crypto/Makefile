# $NetBSD: Makefile,v 1.22 2011/10/30 13:30:36 obache Exp $
#

DISTNAME=	pycrypto-2.4
PKGNAME=	${DISTNAME:S/^py/${PYPKGPREFIX}-/}
CATEGORIES=	security python
MASTER_SITES=	http://ftp.dlitz.net/pub/dlitz/crypto/pycrypto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dlitz.net/software/pycrypto/
COMMENT=	Cryptographic and hash functions for Python
# mostly public domain, but a few bits are:
LICENSE=	python-software-foundation

CONFLICTS+=	${PYPKGPREFIX}-amkCrypto-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

do-test:
	${RUN}cd ${WRKSRC};${SETENV} ${TEST_ENV} ${PYTHONBIN} ${PYSETUP} test

PLIST_VARS+=	py25 py2x
.include "../../lang/python/pyversion.mk"
.if empty(PYPKGPREFIX:Mpy24)
PLIST.py25=	yes
.endif
.if empty(PYPKGPREFIX:Mpy3?)
PLIST.py2x=	yes
.endif

BUILDLINK_API_DEPENDS.gmp+=	gmp>=5.0
.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
