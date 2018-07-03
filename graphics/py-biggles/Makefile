# $NetBSD: Makefile,v 1.24 2018/07/03 05:03:19 adam Exp $

DISTNAME=	python2-biggles-1.6.6
PKGNAME=	${PYPKGPREFIX}${DISTNAME:S/python2//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=biggles/}

MAINTAINER=	Kai.Puolamaki@iki.fi
HOMEPAGE=	http://biggles.sourceforge.net/
COMMENT=	Python module for creating 2D scientific plots

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not ported yet as of 1.6.6

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
