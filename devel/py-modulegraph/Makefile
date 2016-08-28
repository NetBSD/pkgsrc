# $NetBSD: Makefile,v 1.7 2016/08/28 15:48:30 wiz Exp $

DISTNAME=	modulegraph-0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/modulegraph/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://bitbucket.org/ronaldoussoren/modulegraph
COMMENT=	Python module dependency analysis tool
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-altgraph>=0.11:../../graphics/py-altgraph

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/modulegraph \
		${DESTDIR}${PREFIX}/bin/modulegraph${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
