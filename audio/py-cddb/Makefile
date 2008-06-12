# $NetBSD: Makefile,v 1.13 2008/06/12 02:14:14 joerg Exp $
#

DISTNAME=	CDDB-1.4
PKGNAME=	${PYPKGPREFIX}-cddb-1.4
PKGREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cddb-py/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://cddb-py.sourceforge.net/
COMMENT=	Python module to access the CDDB online database

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
