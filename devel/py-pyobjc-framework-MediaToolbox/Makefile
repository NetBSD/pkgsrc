# $NetBSD: Makefile,v 1.3 2024/06/06 14:48:38 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_MediaToolbox-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-MediaToolbox/}

COMMENT=	Wrappers for the framework MediaToolbox on macOS

NOT_FOR_PLATFORM=	Darwin-1[0-2].*-* Darwin-[0-9].*-* # 10.9+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
