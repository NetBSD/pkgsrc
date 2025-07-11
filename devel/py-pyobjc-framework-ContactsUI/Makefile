# $NetBSD: Makefile,v 1.7 2025/07/11 09:03:55 adam Exp $

PYOBJC_FRAMEWORK=	ContactsUI

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-1[0-4].*-* Darwin-[0-9].*-* # 10.11+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Contacts>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Contacts

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
