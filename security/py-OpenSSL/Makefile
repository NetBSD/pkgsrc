# $NetBSD: Makefile,v 1.2 2004/03/26 02:27:53 wiz Exp $
#

DISTNAME=	pyOpenSSL-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
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
