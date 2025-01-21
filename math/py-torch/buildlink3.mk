# $NetBSD: buildlink3.mk,v 1.1 2025/01/21 13:36:49 ryoon Exp $

BUILDLINK_TREE+=	py-torch

.if !defined(PY_TORCH_BUILDLINK3_MK)
PY_TORCH_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-torch+=	${PYPKGPREFIX}-torch>=2.5.1
BUILDLINK_PKGSRCDIR.py-torch?=		../../math/py-torch

.endif	# PY_TORCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-torch
