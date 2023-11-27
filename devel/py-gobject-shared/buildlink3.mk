# $NetBSD: buildlink3.mk,v 1.15 2023/11/27 15:06:25 jperkin Exp $

BUILDLINK_TREE+=	py-gobject-shared

.if !defined(PY_GOBJECT_SHARED_BUILDLINK3_MK)
PY_GOBJECT_SHARED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-gobject-shared+=	py-gobject-shared>=2.10.1
BUILDLINK_ABI_DEPENDS.py-gobject-shared+=	py-gobject-shared>=2.28.7nb5
BUILDLINK_PKGSRCDIR.py-gobject-shared?=		../../devel/py-gobject-shared
BUILDLINK_DEPMETHOD.py-gobject-shared?=		build

.endif # PY_GOBJECT_SHARED_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-gobject-shared
