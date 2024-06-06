# $NetBSD: Makefile,v 1.3 2024/06/06 14:48:34 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_DataDetection-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-DataDetection/}

COMMENT=	Wrappers for the framework DataDetection on macOS

NOT_FOR_PLATFORM=	Darwin-20.*-* Darwin-1[0-9].*-* Darwin-[0-9].*-* # 12.0+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
