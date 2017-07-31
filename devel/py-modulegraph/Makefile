# $NetBSD: Makefile,v 1.9 2017/07/31 05:18:56 adam Exp $

DISTNAME=	modulegraph-0.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/modulegraph/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://bitbucket.org/ronaldoussoren/modulegraph
COMMENT=	Python module dependency analysis tool
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-altgraph>=0.12:../../graphics/py-altgraph

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} modulegraph modulegraph${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
