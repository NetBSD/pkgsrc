# $NetBSD: Makefile,v 1.1 2018/05/12 22:06:53 minskim Exp $

DISTNAME=	backtrader-1.9.58.122
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_GITHUB:=mementum/}
GITHUB_PROJECT=	backtrader
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/mementum/backtrader
COMMENT=	Python Backtesting library for trading strategies
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas

.include "../../lang/python/egg.mk"

post-install:
.for f in bt-run.py btrun
	${MV} ${DESTDIR}${PREFIX}/bin/${f} \
		${DESTDIR}${PREFIX}/bin/${f}${PYVERSSUFFIX}
.endfor

.include "../../mk/bsd.pkg.mk"
