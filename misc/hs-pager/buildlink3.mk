# $NetBSD: buildlink3.mk,v 1.1 2023/10/31 15:33:10 pho Exp $

BUILDLINK_TREE+=	hs-pager

.if !defined(HS_PAGER_BUILDLINK3_MK)
HS_PAGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pager+=	hs-pager>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-pager+=	hs-pager>=0.1.1.0
BUILDLINK_PKGSRCDIR.hs-pager?=		../../misc/hs-pager

.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.endif	# HS_PAGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pager
