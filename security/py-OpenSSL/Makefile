# $NetBSD: Makefile,v 1.7 2005/04/11 21:47:18 tv Exp $
#

DISTNAME=	pyOpenSSL-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyopenssl/}

MAINTAINER=     goteki@users.sourceforge.net
HOMEPAGE=       http://pyopenssl.sourceforge.net/
COMMENT=        Python interface to the OpenSSL library

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
