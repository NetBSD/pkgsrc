# $NetBSD: buildlink3.mk,v 1.13 2020/03/08 16:42:26 bsiegert Exp $

BUILDLINK_TREE+=	py-gobject-shared

.if !defined(PY_GOBJECT_SHARED_BUILDLINK3_MK)
PY_GOBJECT_SHARED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-gobject-shared+=	py-gobject-shared>=2.10.1
BUILDLINK_ABI_DEPENDS.py-gobject-shared+=	py-gobject-shared>=2.28.7nb4
BUILDLINK_PKGSRCDIR.py-gobject-shared?=		../../devel/py-gobject-shared
BUILDLINK_DEPMETHOD.py-gobject-shared?=		build

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.endif # PY_GOBJECT_SHARED_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-gobject-shared
