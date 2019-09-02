# $NetBSD: Makefile,v 1.20 2019/09/02 13:19:55 adam Exp $

DISTNAME=	SSLCrypto-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	security python
MASTER_SITES=	http://www.freenet.org.nz/python/SSLCrypto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freenet.org.nz/python/SSLCrypto/
COMMENT=	Python bindings for openssl

DEPENDS+=	${PYPKGPREFIX}-pyrex>=0.9.4.1:../../lang/py-pyrex

PYTHON_VERSIONS_ACCEPTED=	 27 # py-pyrex

.include "../../lang/python/distutils.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
