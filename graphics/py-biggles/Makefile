# $NetBSD: Makefile,v 1.1.1.1 2004/02/21 03:25:04 minskim Exp $
#

DISTNAME=	python-biggles-1.6.3
PKGNAME=        ${PYPKGPREFIX}${DISTNAME:S/python//}
CATEGORIES=	graphics
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
