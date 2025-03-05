# $NetBSD: buildlink3.mk,v 1.9 2025/03/05 03:39:25 pho Exp $

BUILDLINK_TREE+=	hs-repline

.if !defined(HS_REPLINE_BUILDLINK3_MK)
HS_REPLINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-repline+=	hs-repline>=0.4.2
BUILDLINK_ABI_DEPENDS.hs-repline+=	hs-repline>=0.4.2.0nb6
BUILDLINK_PKGSRCDIR.hs-repline?=	../../devel/hs-repline
.endif	# HS_REPLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-repline
