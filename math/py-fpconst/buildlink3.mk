# $NetBSD: buildlink3.mk,v 1.4 2006/04/12 10:27:26 rillig Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_FPCONST_BUILDLINK3_MK:=	${PY_FPCONST_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	py-fpconst
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npy-fpconst}
BUILDLINK_PACKAGES+=	py-fpconst

.if !empty(PY_FPCONST_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.py-fpconst+=	${PYPKGPREFIX}-fpconst>=0.7.0
BUILDLINK_ABI_DEPENDS.py-fpconst?=	${PYPKGPREFIX}-fpconst>=0.7.0nb1
BUILDLINK_PKGSRCDIR.py-fpconst?=	../../math/py-fpconst
.endif	# PY_FPCONST_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
