# $NetBSD: Makefile,v 1.3 2015/11/18 21:48:19 khorben Exp $
#

VERS=		1.3.1
DISTNAME=	pygraphviz-${VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://pypi.python.org/packages/source/p/pygraphviz/

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://networkx.lanl.gov/pygraphviz/index.html
COMMENT=	Python interface to the Graphviz package
LICENSE=	original-bsd

PYDISTUTILSPKG=	yes

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
