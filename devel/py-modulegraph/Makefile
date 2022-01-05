# $NetBSD: Makefile,v 1.17 2022/01/05 15:41:06 wiz Exp $

DISTNAME=	modulegraph-0.19.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/modulegraph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ronaldoussoren/modulegraph
COMMENT=	Python module dependency analysis tool
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-altgraph>=0.15:../../graphics/py-altgraph
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} modulegraph modulegraph-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
