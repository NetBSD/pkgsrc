# $NetBSD: Makefile,v 1.6 2006/02/05 23:09:38 joerg Exp $
#

DISTNAME=	python-biggles-1.6.3
PKGNAME=        ${PYPKGPREFIX}${DISTNAME:S/python//}
PKGREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=biggles/}

MAINTAINER=	Kai.Puolamaki@iki.fi
HOMEPAGE=	http://biggles.sourceforge.net/
COMMENT= 	Python module for creating 2D scientific plots

PYDISTUTILSPKG= yes
PYBINMODULE=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
