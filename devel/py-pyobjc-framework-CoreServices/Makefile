# $NetBSD: Makefile,v 1.4 2022/09/27 18:12:51 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-CoreServices-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-CoreServices/}

COMMENT=	Wrappers for the framework CoreServices on macOS

USE_LANGUAGES=	c objc

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-FSEvents>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-FSEvents

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
