# $NetBSD: buildlink3.mk,v 1.1 2022/02/24 01:18:23 pho Exp $

BUILDLINK_TREE+=	hs-hostname

.if !defined(HS_HOSTNAME_BUILDLINK3_MK)
HS_HOSTNAME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hostname+=	hs-hostname>=1.0
BUILDLINK_ABI_DEPENDS.hs-hostname+=	hs-hostname>=1.0
BUILDLINK_PKGSRCDIR.hs-hostname?=	../../sysutils/hs-hostname
.endif	# HS_HOSTNAME_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hostname
