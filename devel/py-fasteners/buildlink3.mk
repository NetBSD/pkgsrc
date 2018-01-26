# $NetBSD: buildlink3.mk,v 1.1 2018/01/26 14:44:35 triaxx Exp $

BUILDLINK_TREE+=	py-fasteners

.if !defined(PY_FASTENERS_BUILDLINK3_MK)
PY_FASTENERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-fasteners+=	${PYPKGPREFIX}-fasteners>=0.10
BUILDLINK_PKGSRCDIR.py-fasteners?=	../../devel/py-fasteners
.endif	# PY_FASTENERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-fasteners
