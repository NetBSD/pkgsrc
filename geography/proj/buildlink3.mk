# $NetBSD: buildlink3.mk,v 1.4 2018/03/02 01:13:10 gdt Exp $

BUILDLINK_TREE+=	proj

.if !defined(PROJ_BUILDLINK3_MK)
PROJ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.proj+=	proj>=5.0.0
BUILDLINK_ABI_DEPENDS.proj+=	proj>=5.0.0
BUILDLINK_PKGSRCDIR.proj?=	../../geography/proj
.endif # PROJ_BUILDLINK3_MK

BUILDLINK_TREE+=	-proj
