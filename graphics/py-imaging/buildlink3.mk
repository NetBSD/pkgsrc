# $NetBSD: buildlink3.mk,v 1.16 2012/05/07 01:53:37 dholland Exp $

BUILDLINK_TREE+=	pyimaging

.if !defined(PY_IMAGING_BUILDLINK3_MK)
PY_IMAGING_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pyimaging+=	${PYPKGPREFIX}-imaging>=1.1.4
BUILDLINK_ABI_DEPENDS.pyimaging+=	${PYPKGPREFIX}-imaging>=1.1.7nb1
BUILDLINK_PKGSRCDIR.pyimaging?=	../../graphics/py-imaging

.include "../../mk/jpeg.buildlink3.mk"
.endif # PY_IMAGING_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyimaging
