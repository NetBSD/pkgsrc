# $NetBSD: buildlink3.mk,v 1.5 2021/04/23 12:47:27 pho Exp $

BUILDLINK_TREE+=	hs-syb

.if !defined(HS_SYB_BUILDLINK3_MK)
HS_SYB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-syb+=	hs-syb>=0.7.2.1
BUILDLINK_ABI_DEPENDS.hs-syb+=	hs-syb>=0.7.2.1
BUILDLINK_PKGSRCDIR.hs-syb?=	../../devel/hs-syb
.endif	# HS_SYB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-syb
