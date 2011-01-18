# $NetBSD: Makefile,v 1.21 2011/01/18 12:06:57 drochner Exp $
#

DISTNAME=	pycrypto-2.3
PKGNAME=	${PYPKGPREFIX}-crypto-2.3
CATEGORIES=	security python
MASTER_SITES=	http://ftp.dlitz.net/pub/dlitz/crypto/pycrypto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dlitz.net/software/pycrypto/
COMMENT=	Cryptographic and hash functions for Python
# mostly public domain, but a few bits are:
LICENSE=	python-software-foundation

CONFLICTS+=	${PYPKGPREFIX}-amkCrypto-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=			python
SUBST_STAGE.python=		post-patch
SUBST_MESSAGE.python=	Fix hardcoded paths
SUBST_FILES.python=		lib/Crypto/Util/RFC1751.py
SUBST_SED.python=		-e 's,@@PYTHON@@,${PYTHONBIN},'

SUBST_CLASSES+=			libdir
SUBST_STAGE.libdir=		post-patch
SUBST_MESSAGE.libdir=	Fix hardcoded libraries directory paths
SUBST_FILES.libdir+=	setup.py
SUBST_SED.libdir=		-e 's,@@LIBDIR@@,${PREFIX}/lib,'

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
