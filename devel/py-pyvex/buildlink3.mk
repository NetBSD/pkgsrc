# $NetBSD: buildlink3.mk,v 1.1 2018/03/15 02:49:25 khorben Exp $

BUILDLINK_TREE+=	py-pyvex

.if !defined(PY_PYVEX_BUILDLINK3_MK)
PY_PYVEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-pyvex+=	${PYPKGPREFIX}-pyvex>=7.8.2.21
BUILDLINK_PKGSRCDIR.py-pyvex?=		../../devel/py-pyvex
.endif  # PY_PYVEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pyvex
