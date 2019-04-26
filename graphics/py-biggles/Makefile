# $NetBSD: Makefile,v 1.26 2019/04/26 14:12:40 maya Exp $

DISTNAME=	python2-biggles-1.6.6
PKGNAME=	${PYPKGPREFIX}${DISTNAME:S/python2//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=biggles/}

MAINTAINER=	Kai.Puolamaki@iki.fi
HOMEPAGE=	http://biggles.sourceforge.net/
COMMENT=	Python module for creating 2D scientific plots

PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not ported yet as of 1.6.6

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
