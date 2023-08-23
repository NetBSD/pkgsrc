# $NetBSD: Makefile,v 1.5 2023/08/23 15:49:49 adam Exp $

DISTNAME=	debugpy-1.6.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/debugpy/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/microsoft/debugpy
COMMENT=	Implementation of the Debug Adapter Protocol for Python
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

PLIST_VARS+=	frame_eval
.include "../../lang/python/pyversion.mk"

# pydevd_frame_evaluator is not available for Python 3.11
# see src/debugpy/_vendored/pydevd/setup_pydevd_cython.py
.if ${PYTHON_VERSION} < 311
PLIST.frame_eval=	yes
.endif

post-extract:
	${FIND} ${WRKSRC} -type d -exec ${CHMOD} 755 {} +
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} 644 {} +

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
