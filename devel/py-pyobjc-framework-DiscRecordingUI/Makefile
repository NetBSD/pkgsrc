# $NetBSD: Makefile,v 1.2 2023/11/19 17:02:55 adam Exp $

.include "../../devel/py-pyobjc/Makefile.common"

DISTNAME=	pyobjc-framework-DiscRecordingUI-${PYOBJC_VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyobjc-framework-DiscRecordingUI/}

COMMENT=	Wrappers for the framework DiscRecordingUI on macOS

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Cocoa
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-DiscRecording>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-DiscRecording

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
