# $NetBSD: buildlink.mk,v 1.1 2002/01/22 18:08:56 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pyimaging?= ${PYPKGPREFIX}-imaging-*
DEPENDS+= ${BUILDLINK_DEPENDS.pyimaging}:../../graphics/py-imaging
