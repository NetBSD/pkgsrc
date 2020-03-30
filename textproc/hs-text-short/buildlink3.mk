# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:48:43 riastradh Exp $

BUILDLINK_TREE+=	hs-text-short

.if !defined(HS_TEXT_SHORT_BUILDLINK3_MK)
HS_TEXT_SHORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text-short+=	hs-text-short>=0.1.3
BUILDLINK_ABI_DEPENDS.hs-text-short+=	hs-text-short>=0.1.3
BUILDLINK_PKGSRCDIR.hs-text-short?=	../../textproc/hs-text-short
.endif	# HS_TEXT_SHORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text-short
