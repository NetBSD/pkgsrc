# $NetBSD: buildlink3.mk,v 1.4 2025/02/02 13:05:12 pho Exp $

BUILDLINK_TREE+=	hs-isocline

.if !defined(HS_ISOCLINE_BUILDLINK3_MK)
HS_ISOCLINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-isocline+=	hs-isocline>=1.0.9
BUILDLINK_ABI_DEPENDS.hs-isocline+=	hs-isocline>=1.0.9nb3
BUILDLINK_PKGSRCDIR.hs-isocline?=	../../devel/hs-isocline
.endif	# HS_ISOCLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-isocline
