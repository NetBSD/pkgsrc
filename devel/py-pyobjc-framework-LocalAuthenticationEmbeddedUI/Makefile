# $NetBSD: Makefile,v 1.1 2022/09/27 18:12:55 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-LocalAuthenticationEmbeddedUI-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-LocalAuthenticationEmbeddedUI/}

COMMENT=	Wrappers for the framework LocalAuthenticationEmbeddedUI on macOS

NOT_FOR_PLATFORM=	Darwin-20.*-* Darwin-1[0-9].*-* Darwin-[0-9].*-* # 12.0+

USE_LANGUAGES=	c objc

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-LocalAuthentication>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-LocalAuthentication

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
