# $NetBSD: buildlink3.mk,v 1.1 2004/08/13 08:57:14 recht Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_FPCONST_BUILDLINK3_MK:=	${PY_FPCONST_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	py-fpconst
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npy-fpconst}
BUILDLINK_PACKAGES+=	py-fpconst

.if !empty(PY_FPCONST_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.py-fpconst+=	${PYPKGPREFIX}-fpconst>=0.7.0
BUILDLINK_PKGSRCDIR.py-fpconst?=	../../math/py-fpconst
.endif	# PY_FPCONST_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
