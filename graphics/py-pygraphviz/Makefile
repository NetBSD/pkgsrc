# $NetBSD: Makefile,v 1.27 2024/10/14 06:45:45 wiz Exp $

DISTNAME=	pygraphviz-1.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygraphviz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pygraphviz.github.io/
COMMENT=	Python interface to the Graphviz package
LICENSE=	original-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
