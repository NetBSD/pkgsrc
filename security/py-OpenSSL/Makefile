# $NetBSD: Makefile,v 1.1.1.1 2004/02/19 01:18:52 minskim Exp $
#

DISTNAME=	pyOpenSSL-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyopenssl/}

MAINTAINER=     adam@monkeybyte.org
HOMEPAGE=       http://pyopenssl.sourceforge.net/
COMMENT=        Python interface to the OpenSSL library

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
USE_BUILDLINK3= yes

.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
