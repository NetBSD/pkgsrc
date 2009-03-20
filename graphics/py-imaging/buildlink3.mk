# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:44 joerg Exp $

BUILDLINK_TREE+=	pyimaging

.if !defined(PY_IMAGING_BUILDLINK3_MK)
PY_IMAGING_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pyimaging+=	${PYPKGPREFIX}-imaging>=1.1.4
BUILDLINK_ABI_DEPENDS.pyimaging?=	${PYPKGPREFIX}-imaging>=1.1.5nb1
BUILDLINK_PKGSRCDIR.pyimaging?=	../../graphics/py-imaging

.include "../../graphics/jpeg/buildlink3.mk"
.endif # PY_IMAGING_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyimaging
