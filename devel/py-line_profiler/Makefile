# $NetBSD: Makefile,v 1.3 2017/10/17 18:37:22 adam Exp $

DISTNAME=	line_profiler-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/line_profiler/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rkern/line_profiler
COMMENT=	Python line-by-line profiler
LICENSE=	modified-bsd

USE_LANGUAGES=	c

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} kernprof kernprof${PYVERSSUFFIX} || ${TRUE}

PYTHON_VERSIONED_DEPENDENCIES=	ipython

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
