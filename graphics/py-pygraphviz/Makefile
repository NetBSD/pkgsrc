# $NetBSD: Makefile,v 1.30 2025/10/09 08:01:57 wiz Exp $

DISTNAME=	pygraphviz-1.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygraphviz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pygraphviz.github.io/
COMMENT=	Python interface to the Graphviz package
LICENSE=	original-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools

USE_TOOLS+=	pkg-config

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
