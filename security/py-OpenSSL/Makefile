# $NetBSD: Makefile,v 1.9 2006/02/05 23:10:46 joerg Exp $
#

DISTNAME=	pyOpenSSL-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyopenssl/}

MAINTAINER=	rpaulo@NetBSD.org
HOMEPAGE=       http://pyopenssl.sourceforge.net/
COMMENT=        Python interface to the OpenSSL library

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
