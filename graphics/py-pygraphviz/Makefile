# $NetBSD: Makefile,v 1.5 2018/07/17 13:05:05 adam Exp $

DISTNAME=	pygraphviz-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygraphviz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pygraphviz.github.io/
COMMENT=	Python interface to the Graphviz package
LICENSE=	original-bsd

USE_TOOLS+=	pkg-config

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
