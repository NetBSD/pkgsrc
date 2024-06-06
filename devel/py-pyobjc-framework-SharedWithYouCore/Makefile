# $NetBSD: Makefile,v 1.3 2024/06/06 14:48:43 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_SharedWithYouCore-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-SharedWithYouCore/}

COMMENT=	Wrappers for the framework SharedWithYouCore on macOS

NOT_FOR_PLATFORM=	Darwin-2[0-1].*-* Darwin-1[0-9].*-* Darwin-[0-9].*-* # 13+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
