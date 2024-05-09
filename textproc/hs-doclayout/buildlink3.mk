# $NetBSD: buildlink3.mk,v 1.13 2024/05/09 01:32:41 pho Exp $

BUILDLINK_TREE+=	hs-doclayout

.if !defined(HS_DOCLAYOUT_BUILDLINK3_MK)
HS_DOCLAYOUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-doclayout+=	hs-doclayout>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-doclayout+=	hs-doclayout>=0.4.0.1nb2
BUILDLINK_PKGSRCDIR.hs-doclayout?=	../../textproc/hs-doclayout

.include "../../converters/hs-emojis/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.endif	# HS_DOCLAYOUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-doclayout
