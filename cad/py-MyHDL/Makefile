# $NetBSD: Makefile,v 1.3 2003/08/31 20:27:33 jdolecek Exp $
#

DISTNAME=	myhdl-0.2
PKGNAME=	${PYPKGPREFIX}-MyHDL-0.2
CATEGORIES=	cad
MASTER_SITES=	http://jandecaluwe.com/Tools/MyHDL/

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://jandecaluwe.com/Tools/MyHDL/Overview.html
COMMENT=	Hardware description in Python

USE_BUILDLINK2=	YES
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	22 22pth 23 23pth

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
