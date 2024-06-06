# $NetBSD: Makefile,v 1.8 2024/06/06 14:48:37 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_LaunchServices-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-LaunchServices/}

COMMENT=	Wrappers for the framework LaunchServices on macOS

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreServices>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreServices

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
