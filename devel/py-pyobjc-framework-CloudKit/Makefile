# $NetBSD: Makefile,v 1.4 2023/11/19 17:02:52 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-CloudKit-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-CloudKit/}

COMMENT=	Wrappers for the framework CloudKit on macOS

NOT_FOR_PLATFORM=	Darwin-1[0-3].*-* Darwin-[0-9].*-* # 10.10+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Accounts>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Accounts
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreData>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreData
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreLocation>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreLocation

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
