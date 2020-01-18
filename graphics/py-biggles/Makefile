# $NetBSD: Makefile,v 1.28 2020/01/18 23:32:17 rillig Exp $

DISTNAME=	python2-biggles-1.6.6
PKGNAME=	${PYPKGPREFIX}${DISTNAME:S/python2//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=biggles/}

MAINTAINER=	Kai.Puolamaki@iki.fi
HOMEPAGE=	https://biggles.sourceforge.net/
COMMENT=	Python module for creating 2D scientific plots

PYTHON_VERSIONS_ACCEPTED=	27 # not ported yet as of 1.6.6

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
