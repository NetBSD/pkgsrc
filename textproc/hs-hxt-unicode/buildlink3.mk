# $NetBSD: buildlink3.mk,v 1.1 2020/01/17 15:59:25 pho Exp $

BUILDLINK_TREE+=	hs-hxt-unicode

.if !defined(HS_HXT_UNICODE_BUILDLINK3_MK)
HS_HXT_UNICODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-unicode+=	hs-hxt-unicode>=9.0.2
BUILDLINK_ABI_DEPENDS.hs-hxt-unicode+=	hs-hxt-unicode>=9.0.2.4
BUILDLINK_PKGSRCDIR.hs-hxt-unicode?=	../../textproc/hs-hxt-unicode

.include "../../textproc/hs-hxt-charproperties/buildlink3.mk"
.endif	# HS_HXT_UNICODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-unicode
