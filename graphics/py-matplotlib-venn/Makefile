# $NetBSD: Makefile,v 1.5 2022/01/04 20:54:06 wiz Exp $

DISTNAME=	matplotlib-venn-0.11.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/matplotlib-venn/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/konstantint/matplotlib-venn
COMMENT=	Routines for plotting area-weighted venn diagrams
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-scipy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
