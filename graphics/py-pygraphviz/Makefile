# $NetBSD: Makefile,v 1.28 2024/11/11 07:28:36 wiz Exp $

DISTNAME=	pygraphviz-1.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygraphviz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pygraphviz.github.io/
COMMENT=	Python interface to the Graphviz package
LICENSE=	original-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
