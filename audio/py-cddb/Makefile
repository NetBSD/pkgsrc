# $NetBSD: Makefile,v 1.3 2002/01/17 11:33:41 drochner Exp $
#

DISTNAME=	CDDB-1.3
PKGNAME=	${PYPKGPREFIX}-cddb-1.3
CATEGORIES=	audio
MASTER_SITES=	http://ftp1.sourceforge.net/cddb-py/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://cddb-py.sourceforge.net/
COMMENT=	python module to access the CDDB online database

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
