# $NetBSD: buildlink3.mk,v 1.10 2018/01/07 13:03:59 rillig Exp $

BUILDLINK_TREE+=	pymetakit

.if !defined(PY_METAKIT_BUILDLINK3_MK)
PY_METAKIT_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pymetakit+=	${PYPKGPREFIX}-metakit-[0-9]*
BUILDLINK_ABI_DEPENDS.pymetakit+=	${PYPKGPREFIX}-metakit>=2.4.9.3nb2
BUILDLINK_PKGSRCDIR.pymetakit?=		../../databases/py-metakit
.endif # PY_METAKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pymetakit
