# $NetBSD: Makefile,v 1.5 2024/06/06 14:48:30 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_ApplicationServices-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-ApplicationServices/}

COMMENT=	Wrappers for the framework ApplicationServices on macOS

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Quartz>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Quartz

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
