# $NetBSD: buildlink3.mk,v 1.1 2004/04/22 15:14:59 drochner Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
PY_NUMARRAY_BUILDLINK3_MK:=	${PY_NUMARRAY_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pynumarray
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npynumarray}
BUILDLINK_PACKAGES+=	pynumarray

.if !empty(PY_NUMARRAY_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pynumarray+=	${PYPKGPREFIX}-numarray>=0.9
BUILDLINK_PKGSRCDIR.pynumarray?=	../../math/py-numarray
.endif	# PY_NUMARRAY_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
