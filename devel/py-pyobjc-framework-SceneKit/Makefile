# $NetBSD: Makefile,v 1.5 2024/06/06 14:48:41 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_SceneKit-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-SceneKit/}

COMMENT=	Wrappers for the framework SceneKit on macOS

NOT_FOR_PLATFORM=	Darwin-10.*-* Darwin-[0-9].*-* # 10.7+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Quartz>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Quartz

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
