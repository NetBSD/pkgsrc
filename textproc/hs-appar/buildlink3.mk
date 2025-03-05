# $NetBSD: buildlink3.mk,v 1.11 2025/03/05 03:39:55 pho Exp $

BUILDLINK_TREE+=	hs-appar

.if !defined(HS_APPAR_BUILDLINK3_MK)
HS_APPAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-appar+=	hs-appar>=0.1.8
BUILDLINK_ABI_DEPENDS.hs-appar+=	hs-appar>=0.1.8nb10
BUILDLINK_PKGSRCDIR.hs-appar?=		../../textproc/hs-appar
.endif	# HS_APPAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-appar
