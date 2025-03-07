# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 15:53:33 pho Exp $

BUILDLINK_TREE+=	hs-unlifted

.if !defined(HS_UNLIFTED_BUILDLINK3_MK)
HS_UNLIFTED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unlifted+=	hs-unlifted>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-unlifted+=	hs-unlifted>=0.2.2.0
BUILDLINK_PKGSRCDIR.hs-unlifted?=	../../devel/hs-unlifted

.include "../../textproc/hs-text-short/buildlink3.mk"
.endif	# HS_UNLIFTED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unlifted
