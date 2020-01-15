# $NetBSD: buildlink3.mk,v 1.1 2020/01/15 06:45:04 pho Exp $

BUILDLINK_TREE+=	hs-doclayout

.if !defined(HS_DOCLAYOUT_BUILDLINK3_MK)
HS_DOCLAYOUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-doclayout+=	hs-doclayout>=0.3
BUILDLINK_ABI_DEPENDS.hs-doclayout+=	hs-doclayout>=0.3
BUILDLINK_PKGSRCDIR.hs-doclayout?=	../../textproc/hs-doclayout

.include "../../devel/hs-safe/buildlink3.mk"
.endif	# HS_DOCLAYOUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-doclayout
