# $NetBSD: buildlink3.mk,v 1.6 2023/11/02 06:36:53 pho Exp $

BUILDLINK_TREE+=	hs-repline

.if !defined(HS_REPLINE_BUILDLINK3_MK)
HS_REPLINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-repline+=	hs-repline>=0.4.2
BUILDLINK_ABI_DEPENDS.hs-repline+=	hs-repline>=0.4.2.0nb3
BUILDLINK_PKGSRCDIR.hs-repline?=	../../devel/hs-repline
.endif	# HS_REPLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-repline
