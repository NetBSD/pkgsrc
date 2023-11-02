# $NetBSD: buildlink3.mk,v 1.5 2023/11/02 06:36:31 pho Exp $

BUILDLINK_TREE+=	hs-generically

.if !defined(HS_GENERICALLY_BUILDLINK3_MK)
HS_GENERICALLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-generically+=	hs-generically>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-generically?=	hs-generically>=0.1.1nb1
BUILDLINK_PKGSRCDIR.hs-generically?=	../../devel/hs-generically
.endif	# HS_GENERICALLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-generically
