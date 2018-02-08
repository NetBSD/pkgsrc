# $NetBSD: Makefile,v 1.1 2018/02/08 19:54:23 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-MediaPlayer-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-MediaPlayer/}

COMMENT=	Bridge between Python and Objective-C (MediaPlayer framework)

USE_LANGUAGES=	c objc

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-AVFoundation>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-AVFoundation

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
