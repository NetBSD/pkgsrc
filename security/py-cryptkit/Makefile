# $NetBSD: Makefile,v 1.6 2004/07/22 09:16:04 recht Exp $

DISTNAME=	cryptkit-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cryptkit/}

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://cryptkit.sf.net/
COMMENT=	Python Cryptographic Toolkit

PYBINMODULE=	yes
PYDISTUTILSPKG=	yes
USE_BUILDLINK3=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
