# $NetBSD: buildlink3.mk,v 1.7 2004/05/17 21:32:34 seb Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_NUMERIC_BUILDLINK3_MK:=	${PY_NUMERIC_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pynumeric
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npynumeric}
BUILDLINK_PACKAGES+=	pynumeric

.if !empty(PY_NUMERIC_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pynumeric+=	${PYPKGPREFIX}-Numeric-[0-9]*
BUILDLINK_PKGSRCDIR.pynumeric?=	../../math/py-Numeric
.endif	# PY_NUMERIC_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
