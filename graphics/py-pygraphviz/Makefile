# $NetBSD: Makefile,v 1.6 2018/10/11 10:11:31 adam Exp $

DISTNAME=	pygraphviz-1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygraphviz/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pygraphviz.github.io/
COMMENT=	Python interface to the Graphviz package
LICENSE=	original-bsd

#TEST_DEPENDS+=	${PYPKGPREFIX}-doctest-ignore-unicode>=0.1.2:../..
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose

USE_TOOLS+=	pkg-config

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
