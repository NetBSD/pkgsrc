# $NetBSD: Makefile,v 1.1 2014/02/09 15:09:46 rodent Exp $

DISTNAME=	modulegraph-0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/m/modulegraph/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://bitbucket.org/ronaldoussoren/modulegraph
COMMENT=	Python module dependency analysis tool
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-altgraph>=0.11:../../graphics/py-altgraph

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
