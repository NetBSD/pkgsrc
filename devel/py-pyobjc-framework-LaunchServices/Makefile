# $NetBSD: Makefile,v 1.4 2019/01/08 12:08:43 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-LaunchServices-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-LaunchServices/}

COMMENT=	Bridge between Python and Objective-C (LaunchServices framework)

USE_LANGUAGES=	c objc

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreServices>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreServices

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
