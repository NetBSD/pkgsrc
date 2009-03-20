# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:25:01 joerg Exp $

BUILDLINK_TREE+=	proj

.if !defined(PROJ_BUILDLINK3_MK)
PROJ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.proj+=	proj>=4.4.7nb1
BUILDLINK_ABI_DEPENDS.proj?=	proj>=4.4.7nb2
BUILDLINK_PKGSRCDIR.proj?=	../../misc/proj
.endif # PROJ_BUILDLINK3_MK

BUILDLINK_TREE+=	-proj
