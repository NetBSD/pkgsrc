# $NetBSD: buildlink3.mk,v 1.1 2020/01/03 06:44:47 pho Exp $

BUILDLINK_TREE+=	hs-unicode-show

.if !defined(HS_UNICODE_SHOW_BUILDLINK3_MK)
HS_UNICODE_SHOW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unicode-show+=	hs-unicode-show>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-unicode-show+=	hs-unicode-show>=0.1.0.4
BUILDLINK_PKGSRCDIR.hs-unicode-show?=	../../textproc/hs-unicode-show
.endif	# HS_UNICODE_SHOW_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unicode-show
