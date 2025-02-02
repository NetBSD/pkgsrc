# $NetBSD: buildlink3.mk,v 1.4 2025/02/02 13:05:58 pho Exp $

BUILDLINK_TREE+=	hs-text-ansi

.if !defined(HS_TEXT_ANSI_BUILDLINK3_MK)
HS_TEXT_ANSI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-text-ansi+=	hs-text-ansi>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-text-ansi+=	hs-text-ansi>=0.3.0.1nb3
BUILDLINK_PKGSRCDIR.hs-text-ansi?=	../../textproc/hs-text-ansi

.include "../../textproc/hs-text-builder-linear/buildlink3.mk"
.endif	# HS_TEXT_ANSI_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-text-ansi
