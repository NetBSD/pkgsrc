# $NetBSD: Makefile,v 1.1.1.1 2002/01/29 16:23:31 drochner Exp $

DISTNAME=	cryptkit-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cryptkit/}

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://cryptkit.sf.net/
COMMENT=	python Cryptographic Toolkit

PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
