# $NetBSD: Makefile,v 1.3 2024/06/06 14:48:42 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_SecurityFoundation-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-SecurityFoundation/}

COMMENT=	Wrappers for the framework SecurityFoundation on macOS

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Security>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Security

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
