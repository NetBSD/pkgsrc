# $NetBSD: Makefile,v 1.8 2005/01/23 20:41:45 recht Exp $
#

DISTNAME=	myhdl-0.4.1
PKGNAME=	${PYPKGPREFIX}-MyHDL-0.4.1
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myhdl/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://jandecaluwe.com/Tools/MyHDL/Overview.html
COMMENT=	Hardware description in Python

USE_BUILDLINK3=	YES
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	23 24

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
