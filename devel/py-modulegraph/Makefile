# $NetBSD: Makefile,v 1.13 2018/08/19 07:20:28 adam Exp $

DISTNAME=	modulegraph-0.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/modulegraph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/ronaldoussoren/modulegraph
COMMENT=	Python module dependency analysis tool
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-altgraph>=0.15:../../graphics/py-altgraph

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} modulegraph modulegraph${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
