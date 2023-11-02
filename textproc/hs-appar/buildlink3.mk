# $NetBSD: buildlink3.mk,v 1.8 2023/11/02 06:37:27 pho Exp $

BUILDLINK_TREE+=	hs-appar

.if !defined(HS_APPAR_BUILDLINK3_MK)
HS_APPAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-appar+=	hs-appar>=0.1.8
BUILDLINK_ABI_DEPENDS.hs-appar+=	hs-appar>=0.1.8nb7
BUILDLINK_PKGSRCDIR.hs-appar?=		../../textproc/hs-appar
.endif	# HS_APPAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-appar
