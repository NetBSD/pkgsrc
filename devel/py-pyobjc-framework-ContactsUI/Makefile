# $NetBSD: Makefile,v 1.1 2018/02/08 19:54:20 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-ContactsUI-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-ContactsUI/}

COMMENT=	Bridge between Python and Objective-C (ContactsUI framework)

USE_LANGUAGES=	c objc

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Contacts>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Contacts

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
