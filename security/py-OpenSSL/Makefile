# $NetBSD: Makefile,v 1.14 2008/04/25 20:39:11 joerg Exp $
#

DISTNAME=	pyOpenSSL-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyopenssl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyopenssl.sourceforge.net/
COMMENT=	Python interface to the OpenSSL library

PYTHON_VERSIONS_ACCEPTED= 25 24 23

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
