# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:25 wiz Exp $

PKGREVISION= 1
.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-CloudKit-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-CloudKit/}

COMMENT=	Bridge between Python and Objective-C (CloudKit framework)

USE_LANGUAGES=	c objc

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Accounts>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Accounts
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreData>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreData
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreLocation>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreLocation

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
