# $NetBSD: buildlink3.mk,v 1.1 2004/02/18 16:02:01 minskim Exp $
#
# This Makefile fragment is included by packages that use py23pth-Numeric.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PY_NUMERIC_BUILDLINK3_MK:=	${PY_NUMERIC_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	${PYPKGPREFIX}-Numeric-*
.endif

.if !empty(PY_NUMERIC_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			pynumeric
BUILDLINK_DEPENDS.pynumeric+=		${PYPKGPREFIX}-Numeric-*
BUILDLINK_PKGSRCDIR.pynumeric?=		../../math/py-Numeric

.endif # PY_NUMERIC_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
