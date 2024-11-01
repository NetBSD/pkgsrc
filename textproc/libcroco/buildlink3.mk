# $NetBSD: buildlink3.mk,v 1.40 2024/11/01 12:54:37 wiz Exp $

BUILDLINK_TREE+=	libcroco

.if !defined(LIBCROCO_BUILDLINK3_MK)
LIBCROCO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcroco+=	libcroco>=0.6.0
BUILDLINK_ABI_DEPENDS.libcroco+=	libcroco>=0.6.13nb12
BUILDLINK_PKGSRCDIR.libcroco?=		../../textproc/libcroco

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBCROCO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcroco
