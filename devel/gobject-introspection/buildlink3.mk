# $NetBSD: buildlink3.mk,v 1.14 2023/11/29 10:57:19 jperkin Exp $

BUILDLINK_TREE+=	gobject-introspection

.if !defined(GOBJECT_INTROSPECTION_BUILDLINK3_MK)
GOBJECT_INTROSPECTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.6.14nb1
BUILDLINK_ABI_DEPENDS.gobject-introspection+=	gobject-introspection>=1.76.1nb1
BUILDLINK_PKGSRCDIR.gobject-introspection?=	../../devel/gobject-introspection

ALL_ENV+=	GI_SCANNER_DISABLE_CACHE=yes

.if !${BUILDLINK_DEPMETHOD.gobject-introspection:U:Mbuild}
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.endif

.endif	# GOBJECT_INTROSPECTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-gobject-introspection
