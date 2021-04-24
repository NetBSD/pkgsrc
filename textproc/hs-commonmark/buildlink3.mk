# $NetBSD: buildlink3.mk,v 1.1 2021/04/24 19:32:45 pho Exp $

BUILDLINK_TREE+=	hs-commonmark

.if !defined(HS_COMMONMARK_BUILDLINK3_MK)
HS_COMMONMARK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-commonmark+=	hs-commonmark>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-commonmark+=	hs-commonmark>=0.1.1.4
BUILDLINK_PKGSRCDIR.hs-commonmark?=	../../textproc/hs-commonmark
.endif	# HS_COMMONMARK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-commonmark
