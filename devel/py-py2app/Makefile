# $NetBSD: Makefile,v 1.1 2014/02/09 15:25:46 rodent Exp $

DISTNAME=	py2app-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/p/py2app/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://bitbucket.org/ronaldoussoren/py2app
COMMENT=	Create standalone Mac OS X applications with Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-altgraph>=0.10.1:../../graphics/py-altgraph
DEPENDS+=	${PYPKGPREFIX}-modulegraph>=0.10.1:../../devel/py-modulegraph
DEPENDS+=	${PYPKGPREFIX}-macholib>=1.5:../../devel/py-macholib

ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
