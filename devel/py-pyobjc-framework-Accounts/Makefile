# $NetBSD: Makefile,v 1.4 2022/01/04 20:53:24 wiz Exp $

PKGREVISION= 1
.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-Accounts-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-Accounts/}

COMMENT=	Bridge between Python and Objective-C (Accounts framework)

USE_LANGUAGES=	c objc

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
