# $NetBSD: Makefile,v 1.1 2022/09/27 18:12:59 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-ScreenCaptureKit-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-ScreenCaptureKit/}

COMMENT=	Wrappers for the framework ScreenCaptureKit on macOS

NOT_FOR_PLATFORM=	Darwin-20.*-* Darwin-1[0-9].*-* Darwin-[0-9].*-* # 12.3+

USE_LANGUAGES=	c objc

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreMedia>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreMedia

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
