# $NetBSD: buildlink3.mk,v 1.4 2023/10/09 04:54:46 pho Exp $

BUILDLINK_TREE+=	hs-hostname

.if !defined(HS_HOSTNAME_BUILDLINK3_MK)
HS_HOSTNAME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hostname+=	hs-hostname>=1.0
BUILDLINK_ABI_DEPENDS.hs-hostname+=	hs-hostname>=1.0nb3
BUILDLINK_PKGSRCDIR.hs-hostname?=	../../sysutils/hs-hostname
.endif	# HS_HOSTNAME_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hostname
