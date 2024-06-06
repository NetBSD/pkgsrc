# $NetBSD: Makefile,v 1.3 2024/06/06 14:48:39 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_MetalPerformanceShaders-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-MetalPerformanceShaders/}

COMMENT=	Wrappers for the framework MetalPerformanceShaders on macOS

NOT_FOR_PLATFORM=	Darwin-1[0-6].*-* Darwin-[0-9].*-* # 10.13+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Metal>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Metal

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
