# $NetBSD: buildlink3.mk,v 1.5 2022/02/12 08:50:51 pho Exp $

BUILDLINK_TREE+=	hs-commonmark

.if !defined(HS_COMMONMARK_BUILDLINK3_MK)
HS_COMMONMARK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-commonmark+=	hs-commonmark>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-commonmark+=	hs-commonmark>=0.2.1.1nb1
BUILDLINK_PKGSRCDIR.hs-commonmark?=	../../textproc/hs-commonmark

.include "../../textproc/hs-unicode-transforms/buildlink3.mk"
.endif	# HS_COMMONMARK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-commonmark
