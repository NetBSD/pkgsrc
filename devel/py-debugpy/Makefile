# $NetBSD: Makefile,v 1.22 2025/09/22 14:42:57 adam Exp $

DISTNAME=	debugpy-1.8.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/debugpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/debugpy
COMMENT=	Implementation of the Debug Adapter Protocol for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

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
.for bin in debugpy debugpy-adapter
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
