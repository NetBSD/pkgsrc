# $NetBSD: Makefile,v 1.3 2008/04/25 20:39:11 joerg Exp $
#

DISTNAME=	SSLCrypto-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	http://www.freenet.org.nz/python/SSLCrypto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freenet.org.nz/python/SSLCrypto/
COMMENT=	Python bindings for openssl

DEPENDS+=	py24-pyrex>=0.9.4.1:../../lang/py-pyrex

PYTHON_VERSIONS_ACCEPTED=	25 24

PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py build

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py install

.include "../../lang/python/application.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
