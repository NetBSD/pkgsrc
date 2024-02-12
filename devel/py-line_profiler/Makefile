# $NetBSD: Makefile,v 1.15 2024/02/12 14:42:21 adam Exp $

DISTNAME=	line_profiler-4.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/line_profiler/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rkern/line_profiler
COMMENT=	Python line-by-line profiler
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none
# avoid scikit-build
MAKE_ENV+=	LINE_PROFILER_BUILD_METHOD=setuptools
INSTALL_ENV+=	LINE_PROFILER_BUILD_METHOD=setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} kernprof kernprof-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
