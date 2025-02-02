# $NetBSD: buildlink3.mk,v 1.10 2025/02/02 13:05:54 pho Exp $

BUILDLINK_TREE+=	hs-hxt-unicode

.if !defined(HS_HXT_UNICODE_BUILDLINK3_MK)
HS_HXT_UNICODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-unicode+=	hs-hxt-unicode>=9.0.2
BUILDLINK_ABI_DEPENDS.hs-hxt-unicode+=	hs-hxt-unicode>=9.0.2.4nb9
BUILDLINK_PKGSRCDIR.hs-hxt-unicode?=	../../textproc/hs-hxt-unicode

.include "../../textproc/hs-hxt-charproperties/buildlink3.mk"
.endif	# HS_HXT_UNICODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-unicode
