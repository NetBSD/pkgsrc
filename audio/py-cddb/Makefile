# $NetBSD: Makefile,v 1.10 2004/07/22 09:16:00 recht Exp $
#

DISTNAME=	CDDB-1.4
PKGNAME=	${PYPKGPREFIX}-cddb-1.4
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cddb-py/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://cddb-py.sourceforge.net/
COMMENT=	Python module to access the CDDB online database

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
USE_BUILDLINK3=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
