# $NetBSD: buildlink3.mk,v 1.16 2025/02/02 13:05:25 pho Exp $

BUILDLINK_TREE+=	hs-syb

.if !defined(HS_SYB_BUILDLINK3_MK)
HS_SYB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-syb+=	hs-syb>=0.7.2
BUILDLINK_ABI_DEPENDS.hs-syb+=	hs-syb>=0.7.2.4nb3
BUILDLINK_PKGSRCDIR.hs-syb?=	../../devel/hs-syb
.endif	# HS_SYB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-syb
