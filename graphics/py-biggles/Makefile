# $NetBSD: Makefile,v 1.3 2004/10/03 00:14:57 tv Exp $
#

DISTNAME=	python-biggles-1.6.3
PKGNAME=        ${PYPKGPREFIX}${DISTNAME:S/python//}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=biggles/}

MAINTAINER=	Kai.Puolamaki@iki.fi
HOMEPAGE=	http://biggles.sourceforge.net/
COMMENT= 	Python module for creating 2D scientific plots

USE_X11=	yes
PYDISTUTILSPKG= yes
PYBINMODULE=	yes
USE_BUILDLINK3=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
