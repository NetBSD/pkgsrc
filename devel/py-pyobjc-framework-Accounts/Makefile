# $NetBSD: Makefile,v 1.7 2024/06/06 14:48:29 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

WHEEL_NAME=	pyobjc_framework_Accounts-${PYOBJC_VERS}

CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-Accounts/}

COMMENT=	Wrappers for the framework Accounts on macOS

NOT_FOR_PLATFORM=	Darwin-1[0-1].*-* Darwin-[0-9].*-* # 10.8+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
