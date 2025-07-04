# $NetBSD: Makefile,v 1.20 2025/07/04 09:08:35 wiz Exp $

DISTNAME=	line_profiler-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/line_profiler/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/pyutils/line_profiler
COMMENT=	Python line-by-line profiler
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.3:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none
# avoid scikit-build
MAKE_ENV+=	LINE_PROFILER_BUILD_METHOD=setuptools
INSTALL_ENV+=	LINE_PROFILER_BUILD_METHOD=setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} kernprof kernprof-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
