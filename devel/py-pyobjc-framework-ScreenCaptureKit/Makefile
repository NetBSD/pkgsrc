# $NetBSD: Makefile,v 1.2 2023/11/19 17:03:04 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-ScreenCaptureKit-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-ScreenCaptureKit/}

COMMENT=	Wrappers for the framework ScreenCaptureKit on macOS

NOT_FOR_PLATFORM=	Darwin-20.*-* Darwin-1[0-9].*-* Darwin-[0-9].*-* # 12.3+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreMedia>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreMedia

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
