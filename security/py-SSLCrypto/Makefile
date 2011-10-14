# $NetBSD: Makefile,v 1.7 2011/10/14 13:00:01 obache Exp $
#

DISTNAME=	SSLCrypto-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security python
MASTER_SITES=	http://www.freenet.org.nz/python/SSLCrypto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freenet.org.nz/python/SSLCrypto/
COMMENT=	Python bindings for openssl

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-pyrex>=0.9.4.1:../../lang/py-pyrex

PYTHON_VERSIONS_ACCEPTED=	27 26 25 24
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
