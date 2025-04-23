# $NetBSD: Makefile,v 1.4 2025/04/23 12:45:23 adam Exp $

PKGREVISION=	1

PYOBJC_FRAMEWORK=	SharedWithYou

.include "../../devel/py-pyobjc/Makefile.common"

NOT_FOR_PLATFORM=	Darwin-2[0-1].*-* Darwin-1[0-9].*-* Darwin-[0-9].*-* # 13+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-SharedWithYouCore>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-SharedWithYouCore

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
