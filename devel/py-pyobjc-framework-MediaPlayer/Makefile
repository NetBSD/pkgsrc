# $NetBSD: Makefile,v 1.4 2023/11/19 17:03:00 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-MediaPlayer-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-MediaPlayer/}

COMMENT=	Wrappers for the framework MediaPlayer on macOS

NOT_FOR_PLATFORM=	Darwin-1[0-5].*-* Darwin-[0-9].*-* # 10.12+

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-AVFoundation>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-AVFoundation

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
