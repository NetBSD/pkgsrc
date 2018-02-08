# $NetBSD: Makefile,v 1.1 2018/02/08 19:54:25 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-SecurityInterface-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-SecurityInterface/}

COMMENT=	Bridge between Python and Objective-C (SecurityInterface framework)

USE_LANGUAGES=	c objc

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Security>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Security

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
