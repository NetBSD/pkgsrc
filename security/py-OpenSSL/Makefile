# $NetBSD: Makefile,v 1.18 2009/06/26 19:44:47 joerg Exp $
#

DISTNAME=	pyOpenSSL-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyopenssl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyopenssl.sourceforge.net/
COMMENT=	Python interface to the OpenSSL library

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
