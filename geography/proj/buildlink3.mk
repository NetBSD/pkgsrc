# $NetBSD: buildlink3.mk,v 1.3 2015/03/14 18:39:05 gdt Exp $

BUILDLINK_TREE+=	proj

.if !defined(PROJ_BUILDLINK3_MK)
PROJ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.proj+=	proj>=4.9.1
BUILDLINK_ABI_DEPENDS.proj+=	proj>=4.9.1
BUILDLINK_PKGSRCDIR.proj?=	../../geography/proj
.endif # PROJ_BUILDLINK3_MK

BUILDLINK_TREE+=	-proj
