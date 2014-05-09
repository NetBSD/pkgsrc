# $NetBSD: Makefile,v 1.13 2014/05/09 07:37:17 wiz Exp $

DISTNAME=	SSLCrypto-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	security python
MASTER_SITES=	http://www.freenet.org.nz/python/SSLCrypto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freenet.org.nz/python/SSLCrypto/
COMMENT=	Python bindings for openssl

DEPENDS+=	${PYPKGPREFIX}-pyrex>=0.9.4.1:../../lang/py-pyrex

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-pyrex

.include "../../lang/python/distutils.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
