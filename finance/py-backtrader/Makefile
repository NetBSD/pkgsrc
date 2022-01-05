# $NetBSD: Makefile,v 1.6 2022/01/05 15:41:10 wiz Exp $

DISTNAME=	backtrader-1.9.74.123
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	finance python
#MASTER_SITES=	${MASTER_SITE_PYPI:=b/backtrader/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=mementum/}
GITHUB_PROJECT=	backtrader

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/mementum/backtrader
COMMENT=	Python Backtesting library for trading strategies
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-matplotlib, py-pandas

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} bt-run.py bt-run-${PYVERSSUFFIX}.py && \
	${MV} btrun btrun-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
