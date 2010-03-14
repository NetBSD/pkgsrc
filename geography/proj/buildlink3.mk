# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/03/14 16:26:22 wiz Exp $

BUILDLINK_TREE+=	proj

.if !defined(PROJ_BUILDLINK3_MK)
PROJ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.proj+=	proj>=4.4.7nb1
BUILDLINK_ABI_DEPENDS.proj?=	proj>=4.4.7nb2
BUILDLINK_PKGSRCDIR.proj?=	../../geography/proj
.endif # PROJ_BUILDLINK3_MK

BUILDLINK_TREE+=	-proj
