# $NetBSD: Makefile,v 1.12 2024/07/31 18:20:18 adam Exp $

DISTNAME=	matplotlib-venn-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/matplotlib-venn/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/konstantint/matplotlib-venn
COMMENT=	Routines for plotting area-weighted venn diagrams
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
