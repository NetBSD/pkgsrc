# $NetBSD: buildlink3.mk,v 1.2 2020/09/28 22:56:38 khorben Exp $

BUILDLINK_TREE+=	py-pyvex

.if !defined(PY_PYVEX_BUILDLINK3_MK)
PY_PYVEX_BUILDLINK3_MK:=

.include "../../devel/py-angr/version.mk"
BUILDLINK_API_DEPENDS.py-pyvex+=	${PYPKGPREFIX}-pyvex>=${ANGR_VERSION}
BUILDLINK_PKGSRCDIR.py-pyvex?=		../../devel/py-pyvex
.endif  # PY_PYVEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pyvex
