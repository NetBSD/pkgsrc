# $NetBSD: Makefile,v 1.5 2004/11/28 23:38:39 wiz Exp $
#

DISTNAME=	pyOpenSSL-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyopenssl/}

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=       http://pyopenssl.sourceforge.net/
COMMENT=        Python interface to the OpenSSL library

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
USE_BUILDLINK3= yes

.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
