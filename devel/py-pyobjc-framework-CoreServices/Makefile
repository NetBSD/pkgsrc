# $NetBSD: Makefile,v 1.6 2024/06/06 14:48:33 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_CoreServices-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-CoreServices/}

COMMENT=	Wrappers for the framework CoreServices on macOS

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-FSEvents>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-FSEvents

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
