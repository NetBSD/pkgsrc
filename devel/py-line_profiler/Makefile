# $NetBSD: Makefile,v 1.5 2018/08/07 16:45:10 minskim Exp $

DISTNAME=	line_profiler-2.1.2
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

.include "../../lang/python/pyversion.mk"

PLIST_VARS+=	py35
.if "${PYPKGPREFIX}" != "py27" && "${PYPKGPREFIX}" != "py34"
PLIST.py35=	yes
.endif

.if "${PYPKGPREFIX}" == "py37"
# Regenerate _line_profiler.c with recent cython
BUILDLINK_DEPMETHOD.py-cython=	build
.include "../../devel/py-cython/buildlink3.mk"

pre-configure:
	${RM} -f ${WRKSRC}/_line_profiler.c
.endif

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
