# $NetBSD: buildlink3.mk,v 1.6 2022/02/26 03:58:26 pho Exp $

BUILDLINK_TREE+=	hs-commonmark

.if !defined(HS_COMMONMARK_BUILDLINK3_MK)
HS_COMMONMARK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-commonmark+=	hs-commonmark>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-commonmark+=	hs-commonmark>=0.2.1.1nb2
BUILDLINK_PKGSRCDIR.hs-commonmark?=	../../textproc/hs-commonmark

.include "../../textproc/hs-unicode-transforms/buildlink3.mk"
.endif	# HS_COMMONMARK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-commonmark
