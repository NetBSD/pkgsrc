# $NetBSD: Makefile,v 1.2 2017/10/16 12:14:29 adam Exp $

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

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} kernprof kernprof${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
