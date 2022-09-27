# $NetBSD: Makefile,v 1.3 2022/09/27 18:12:53 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-GameplayKit-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-GameplayKit/}

COMMENT=	Wrappers for the framework GameplayKit on macOS

NOT_FOR_PLATFORM=	Darwin-1[0-4].*-* Darwin-[0-9].*-* # 10.11+

USE_LANGUAGES=	c objc

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-SpriteKit>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-SpriteKit

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
