# $NetBSD: buildlink2.mk,v 1.3 2002/10/24 20:44:51 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyimaging
BUILDLINK_DEPENDS.pyimaging?=	${PYPKGPREFIX}-imaging-*
BUILDLINK_PKGSRCDIR.pyimaging?=	../../graphics/py-imaging

EVAL_PREFIX+=	BUILDLINK_PREFIX.pyimaging=${PYPKGPREFIX}-imaging
BUILDLINK_PREFIX.pyimaging_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.pyimaging=	${PYINC}/PIL/ImConfig.h
BUILDLINK_FILES.pyimaging+=	${PYINC}/PIL/ImPlatform.h
BUILDLINK_FILES.pyimaging+=	${PYINC}/PIL/Imaging.h

BUILDLINK_TARGETS+=	pyimaging-buildlink

pyimaging-buildlink: _BUILDLINK_USE
