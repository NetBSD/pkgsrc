# $NetBSD: Makefile,v 1.3 2018/03/12 11:16:48 wiz Exp $

DISTNAME=	pygraphviz-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
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
