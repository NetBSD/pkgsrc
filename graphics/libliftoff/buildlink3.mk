# $NetBSD: buildlink3.mk,v 1.1 2026/04/13 15:43:44 kikadf Exp $

BUILDLINK_TREE+=	libliftoff

.if !defined(LIBLIFTOFF_BUILDLINK3_MK)
LIBLIFTOFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libliftoff+=	libliftoff>=0.5.0
BUILDLINK_ABI_DEPENDS.libliftoff+=	libliftoff>=0.5.0
BUILDLINK_PKGSRCDIR.libliftoff?=	../../graphics/libliftoff

.endif # LIBLIFTOFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libliftoff
