# $NetBSD: Makefile,v 1.4 2003/09/18 04:17:12 jmc Exp $

DISTNAME=	cryptkit-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cryptkit/}

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://cryptkit.sf.net/
COMMENT=	Python Cryptographic Toolkit

PYBINMODULE=	yes
PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
