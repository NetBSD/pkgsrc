# $NetBSD: buildlink3.mk,v 1.5 2006/04/12 10:27:26 rillig Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
PY_NUMARRAY_BUILDLINK3_MK:=	${PY_NUMARRAY_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pynumarray
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npynumarray}
BUILDLINK_PACKAGES+=	pynumarray

.if !empty(PY_NUMARRAY_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.pynumarray+=	${PYPKGPREFIX}-numarray>=1.1.1
BUILDLINK_ABI_DEPENDS.pynumarray?=	${PYPKGPREFIX}-numarray>=1.3.3nb1
BUILDLINK_PKGSRCDIR.pynumarray?=	../../math/py-numarray
.endif	# PY_NUMARRAY_BUILDLINK3_MK

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
