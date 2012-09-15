# $NetBSD: buildlink3.mk,v 1.11 2012/09/15 10:04:19 obache Exp $

BUILDLINK_TREE+=	py-gobject-shared

.if !defined(PY_GOBJECT_SHARED_BUILDLINK3_MK)
PY_GOBJECT_SHARED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-gobject-shared+=	py-gobject-shared>=2.10.1
BUILDLINK_ABI_DEPENDS.py-gobject-shared+=		py-gobject-shared>=2.28.6nb5
BUILDLINK_PKGSRCDIR.py-gobject-shared?=		../../devel/py-gobject-shared
BUILDLINK_DEPMETHOD.py-gobject-shared?=		build

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.endif # PY_GOBJECT_SHARED_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-gobject-shared
