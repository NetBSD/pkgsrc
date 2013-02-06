# $NetBSD: Makefile,v 1.10 2013/02/06 23:21:02 jperkin Exp $
#

DISTNAME=	SSLCrypto-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	security python
MASTER_SITES=	http://www.freenet.org.nz/python/SSLCrypto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freenet.org.nz/python/SSLCrypto/
COMMENT=	Python bindings for openssl

DEPENDS+=	${PYPKGPREFIX}-pyrex>=0.9.4.1:../../lang/py-pyrex

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
