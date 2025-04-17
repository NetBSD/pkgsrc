# $NetBSD: buildlink3.mk,v 1.42 2025/04/17 21:52:35 wiz Exp $

BUILDLINK_TREE+=	libcroco

.if !defined(LIBCROCO_BUILDLINK3_MK)
LIBCROCO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcroco+=	libcroco>=0.6.0
BUILDLINK_ABI_DEPENDS.libcroco+=	libcroco>=0.6.13nb14
BUILDLINK_PKGSRCDIR.libcroco?=		../../textproc/libcroco

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBCROCO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcroco
