# $NetBSD: Makefile,v 1.8 2004/04/11 17:50:33 xtraeme Exp $
#

DISTNAME=	CDDB-1.3
PKGNAME=	${PYPKGPREFIX}-cddb-1.3
CATEGORIES=	audio
MASTER_SITES=	http://ftp1.sourceforge.net/cddb-py/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://cddb-py.sourceforge.net/
COMMENT=	Python module to access the CDDB online database

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
USE_BUILDLINK3=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
