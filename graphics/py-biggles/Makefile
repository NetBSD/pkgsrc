# $NetBSD: Makefile,v 1.10 2007/02/22 19:26:35 wiz Exp $
#

DISTNAME=	python-biggles-1.6.3
PKGNAME=	${PYPKGPREFIX}${DISTNAME:S/python//}
PKGREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=biggles/}

MAINTAINER=	Kai.Puolamaki@iki.fi
HOMEPAGE=	http://biggles.sourceforge.net/
COMMENT=	Python module for creating 2D scientific plots

PYDISTUTILSPKG= yes
PYBINMODULE=	yes
PYTHON_VERSIONS_ACCEPTED=	24 23 22

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
