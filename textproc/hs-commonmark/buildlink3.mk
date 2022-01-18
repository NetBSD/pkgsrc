# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:25 pho Exp $

BUILDLINK_TREE+=	hs-commonmark

.if !defined(HS_COMMONMARK_BUILDLINK3_MK)
HS_COMMONMARK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-commonmark+=	hs-commonmark>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-commonmark+=	hs-commonmark>=0.1.1.4nb2
BUILDLINK_PKGSRCDIR.hs-commonmark?=	../../textproc/hs-commonmark
.endif	# HS_COMMONMARK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-commonmark
