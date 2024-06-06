# $NetBSD: Makefile,v 1.3 2024/06/06 14:48:38 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_MetalFX-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-MetalFX/}

COMMENT=	Wrappers for the framework MetalFX on macOS

NOT_FOR_PLATFORM=	Darwin-2[0-1].*-* Darwin-1[0-9].*-* Darwin-[0-9].*-* # 13+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Metal>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Metal

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
