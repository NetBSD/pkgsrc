# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:28 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyimaging
BUILDLINK_DEPENDS.pyimaging?=	${PYPKGPREFIX}-imaging-*
BUILDLINK_PKGSRCDIR.pyimaging?=	../../graphics/py-imaging
