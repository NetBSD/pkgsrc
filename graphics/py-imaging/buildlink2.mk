# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:22:53 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyimaging
BUILDLINK_DEPENDS.pyimaging?=	${PYPKGPREFIX}-imaging-*
BUILDLINK_PKGSRCDIR.pyimaging?=	../../graphics/py-imaging
