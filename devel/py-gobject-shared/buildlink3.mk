# $NetBSD: buildlink3.mk,v 1.5 2009/03/20 19:24:28 joerg Exp $

BUILDLINK_TREE+=	py-gobject-shared

.if !defined(PY_GOBJECT_SHARED_BUILDLINK3_MK)
PY_GOBJECT_SHARED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-gobject-shared+=	py-gobject-shared>=2.10.1
BUILDLINK_PKGSRCDIR.py-gobject-shared?=		../../devel/py-gobject-shared
BUILDLINK_DEPMETHOD.py-gobject-shared?=		build

.include "../../devel/glib2/buildlink3.mk"
.endif # PY_GOBJECT_SHARED_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-gobject-shared
