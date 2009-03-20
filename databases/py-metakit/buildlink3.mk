# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:07 joerg Exp $

BUILDLINK_TREE+=	pymetakit

.if !defined(PY_METAKIT_BUILDLINK3_MK)
PY_METAKIT_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pymetakit+=	${PYPKGPREFIX}-metakit-[0-9]*
BUILDLINK_ABI_DEPENDS.pymetakit+=	${PYPKGPREFIX}-metakit>=2.4.9.3nb2
BUILDLINK_PKGSRCDIR.pymetakit?=	../../databases/py-metakit
.endif # PY_METAKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pymetakit
