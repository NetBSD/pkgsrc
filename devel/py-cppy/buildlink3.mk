# $NetBSD: buildlink3.mk,v 1.1 2021/05/05 09:28:50 adam Exp $

BUILDLINK_TREE+=		py-cppy

.if !defined(PY_CPPY_BUILDLINK3_MK)
PY_CPPY_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.py-cppy?=	build
BUILDLINK_API_DEPENDS.py-cppy+=	${PYPKGPREFIX}-cppy>=1.1.0
BUILDLINK_PKGSRCDIR.py-cppy?=	../../devel/py-cppy
.endif	# PY_CPPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-cppy
