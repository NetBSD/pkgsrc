# $NetBSD: Makefile,v 1.2 2016/06/08 17:43:33 wiz Exp $

DISTNAME=	pygraphviz-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygraphviz/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://networkx.lanl.gov/pygraphviz/index.html
COMMENT=	Python interface to the Graphviz package
LICENSE=	original-bsd

USE_TOOLS+=	pkg-config

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
