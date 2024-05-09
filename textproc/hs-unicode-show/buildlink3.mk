# $NetBSD: buildlink3.mk,v 1.11 2024/05/09 01:32:49 pho Exp $

BUILDLINK_TREE+=	hs-unicode-show

.if !defined(HS_UNICODE_SHOW_BUILDLINK3_MK)
HS_UNICODE_SHOW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unicode-show+=	hs-unicode-show>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-unicode-show+=	hs-unicode-show>=0.1.1.1nb4
BUILDLINK_PKGSRCDIR.hs-unicode-show?=	../../textproc/hs-unicode-show

.include "../../devel/hs-safe/buildlink3.mk"
.endif	# HS_UNICODE_SHOW_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unicode-show
