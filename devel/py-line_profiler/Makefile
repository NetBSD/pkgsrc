# $NetBSD: Makefile,v 1.1 2017/03/17 21:30:35 minskim Exp $

DISTNAME=	line_profiler-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/line_profiler/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rkern/line_profiler
COMMENT=	Python line-by-line profiler
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-ipython>0.13:../../devel/py-ipython

USE_LANGUAGES=	c

.include "../../lang/python/egg.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/kernprof \
		${DESTDIR}${PREFIX}/bin/kernprof${PYVERSSUFFIX}

.include "../../mk/bsd.pkg.mk"
