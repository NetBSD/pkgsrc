# $NetBSD: Makefile,v 1.5 2004/04/27 05:44:22 snj Exp $

DISTNAME=	cryptkit-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cryptkit/}

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://cryptkit.sf.net/
COMMENT=	Python Cryptographic Toolkit

PYBINMODULE=	yes
PYDISTUTILSPKG=	yes
USE_BUILDLINK3=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
