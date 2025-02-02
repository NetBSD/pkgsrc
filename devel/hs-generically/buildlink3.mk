# $NetBSD: buildlink3.mk,v 1.7 2025/02/02 13:05:07 pho Exp $

BUILDLINK_TREE+=	hs-generically

.if !defined(HS_GENERICALLY_BUILDLINK3_MK)
HS_GENERICALLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-generically+=	hs-generically>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-generically?=	hs-generically>=0.1.1nb3
BUILDLINK_PKGSRCDIR.hs-generically?=	../../devel/hs-generically
.endif	# HS_GENERICALLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-generically
