# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:58 joerg Exp $

BUILDLINK_TREE+=	py-fpconst

.if !defined(PY_FPCONST_BUILDLINK3_MK)
PY_FPCONST_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-fpconst+=	${PYPKGPREFIX}-fpconst>=0.7.0
BUILDLINK_ABI_DEPENDS.py-fpconst?=	${PYPKGPREFIX}-fpconst>=0.7.0nb1
BUILDLINK_PKGSRCDIR.py-fpconst?=	../../math/py-fpconst
.endif # PY_FPCONST_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-fpconst
