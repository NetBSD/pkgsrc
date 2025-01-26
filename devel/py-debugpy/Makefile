# $NetBSD: Makefile,v 1.17 2025/01/26 15:34:48 he Exp $

DISTNAME=	debugpy-1.8.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/debugpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/debugpy
COMMENT=	Implementation of the Debug Adapter Protocol for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

PLIST_VARS+=	frame_eval pydevd_cython
.include "../../lang/python/pyversion.mk"

# pydevd_frame_evaluator is not available for Python 3.11
# see src/debugpy/_vendored/pydevd/setup_pydevd_cython.py
.if ${PYTHON_VERSION} < 311
PLIST.frame_eval=	yes
.endif
.if ${PYTHON_VERSION} >= 312
PLIST.pydevd_cython=	yes
.endif

post-extract:
	${FIND} ${WRKSRC} -type d -exec ${CHMOD} 755 {} +
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} 644 {} +

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} debugpy debugpy-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
