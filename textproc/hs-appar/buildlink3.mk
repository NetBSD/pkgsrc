# $NetBSD: buildlink3.mk,v 1.7 2023/10/09 04:54:48 pho Exp $

BUILDLINK_TREE+=	hs-appar

.if !defined(HS_APPAR_BUILDLINK3_MK)
HS_APPAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-appar+=	hs-appar>=0.1.8
BUILDLINK_ABI_DEPENDS.hs-appar+=	hs-appar>=0.1.8nb6
BUILDLINK_PKGSRCDIR.hs-appar?=		../../textproc/hs-appar
.endif	# HS_APPAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-appar
