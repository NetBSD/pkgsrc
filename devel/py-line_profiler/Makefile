# $NetBSD: Makefile,v 1.18 2025/01/06 11:49:37 adam Exp $

DISTNAME=	line_profiler-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/line_profiler/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pyutils/line_profiler
COMMENT=	Python line-by-line profiler
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.3:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=68.2.2:../../devel/py-setuptools

USE_LANGUAGES=	# none
# avoid scikit-build
MAKE_ENV+=	LINE_PROFILER_BUILD_METHOD=setuptools
INSTALL_ENV+=	LINE_PROFILER_BUILD_METHOD=setuptools

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} kernprof kernprof-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
