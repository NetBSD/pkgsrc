# $NetBSD: buildlink3.mk,v 1.1 2023/10/31 16:47:43 pho Exp $

BUILDLINK_TREE+=	hs-silently

.if !defined(HS_SILENTLY_BUILDLINK3_MK)
HS_SILENTLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-silently+=	hs-silently>=1.2.5
BUILDLINK_ABI_DEPENDS.hs-silently+=	hs-silently>=1.2.5.3
BUILDLINK_PKGSRCDIR.hs-silently?=	../../devel/hs-silently
.endif	# HS_SILENTLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-silently
