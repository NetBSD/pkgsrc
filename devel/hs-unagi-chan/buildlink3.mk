# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:17 pho Exp $

BUILDLINK_TREE+=	hs-unagi-chan

.if !defined(HS_UNAGI_CHAN_BUILDLINK3_MK)
HS_UNAGI_CHAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unagi-chan+=	hs-unagi-chan>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-unagi-chan+=	hs-unagi-chan>=0.4.1.4nb2
BUILDLINK_PKGSRCDIR.hs-unagi-chan?=	../../devel/hs-unagi-chan

.include "../../devel/hs-atomic-primops/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_UNAGI_CHAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unagi-chan
