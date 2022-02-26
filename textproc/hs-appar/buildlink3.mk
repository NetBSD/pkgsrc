# $NetBSD: buildlink3.mk,v 1.5 2022/02/26 03:58:24 pho Exp $

BUILDLINK_TREE+=	hs-appar

.if !defined(HS_APPAR_BUILDLINK3_MK)
HS_APPAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-appar+=	hs-appar>=0.1.8
BUILDLINK_ABI_DEPENDS.hs-appar+=	hs-appar>=0.1.8nb4
BUILDLINK_PKGSRCDIR.hs-appar?=		../../textproc/hs-appar
.endif	# HS_APPAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-appar
