# $NetBSD: buildlink3.mk,v 1.12 2009/08/26 19:56:42 sno Exp $

BUILDLINK_TREE+=	pyimaging

.if !defined(PY_IMAGING_BUILDLINK3_MK)
PY_IMAGING_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pyimaging+=	${PYPKGPREFIX}-imaging>=1.1.4
BUILDLINK_ABI_DEPENDS.pyimaging?=	py25-imaging>=1.1.6nb1
BUILDLINK_PKGSRCDIR.pyimaging?=	../../graphics/py-imaging

.include "../../graphics/jpeg/buildlink3.mk"
.endif # PY_IMAGING_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyimaging
