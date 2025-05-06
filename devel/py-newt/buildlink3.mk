# $NetBSD: buildlink3.mk,v 1.2 2025/05/06 20:35:02 vins Exp $

BUILDLINK_TREE+=	py-newt

.if !defined(PY_NEWT_BUILDLINK3_MK)
PY_NEWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-newt+=	${PYPKGPREFIX}-newt>=0.52.16
BUILDLINK_ABI_DEPENDS.py-newt+=	${PYPKGPREFIX}-newt>=0.52.25
BUILDLINK_PKGSRCDIR.py-newt?=	../../devel/py-newt

.endif	# PY_NEWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-newt
