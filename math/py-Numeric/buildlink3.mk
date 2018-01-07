# $NetBSD: buildlink3.mk,v 1.16 2018/01/07 13:04:23 rillig Exp $

BUILDLINK_TREE+=	pynumeric

.if !defined(PY_NUMERIC_BUILDLINK3_MK)
PY_NUMERIC_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pynumeric+=	${PYPKGPREFIX}-Numeric-[0-9]*
BUILDLINK_ABI_DEPENDS.pynumeric+=	${PYPKGPREFIX}-Numeric>=23.7nb1
BUILDLINK_PKGSRCDIR.pynumeric?=		../../math/py-Numeric
.endif # PY_NUMERIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-pynumeric
