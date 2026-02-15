# $NetBSD: Makefile,v 1.23 2026/02/15 14:09:28 adam Exp $

DISTNAME=	line_profiler-5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/line_profiler/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pyutils/line_profiler
COMMENT=	Python line-by-line profiler
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.3:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	c c++
# avoid scikit-build
MAKE_ENV+=	LINE_PROFILER_BUILD_METHOD=cython
INSTALL_ENV+=	LINE_PROFILER_BUILD_METHOD=cython

PYTHON_VERSIONS_INCOMPATIBLE=	310

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} kernprof kernprof-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
