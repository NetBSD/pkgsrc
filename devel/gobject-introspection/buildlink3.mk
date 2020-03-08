# $NetBSD: buildlink3.mk,v 1.11 2020/03/08 16:42:25 bsiegert Exp $

BUILDLINK_TREE+=	gobject-introspection

.if !defined(GOBJECT_INTROSPECTION_BUILDLINK3_MK)
GOBJECT_INTROSPECTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.6.14nb1
BUILDLINK_ABI_DEPENDS.gobject-introspection+=	gobject-introspection>=1.62.0nb1
BUILDLINK_PKGSRCDIR.gobject-introspection?=	../../devel/gobject-introspection

ALL_ENV+=	GI_SCANNER_DISABLE_CACHE=yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.endif	# GOBJECT_INTROSPECTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-gobject-introspection
