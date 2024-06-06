# $NetBSD: Makefile,v 1.3 2024/06/06 14:48:37 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_LocalAuthenticationEmbeddedUI-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-LocalAuthenticationEmbeddedUI/}

COMMENT=	Wrappers for the framework LocalAuthenticationEmbeddedUI on macOS

NOT_FOR_PLATFORM=	Darwin-20.*-* Darwin-1[0-9].*-* Darwin-[0-9].*-* # 12.0+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-LocalAuthentication>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-LocalAuthentication

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
