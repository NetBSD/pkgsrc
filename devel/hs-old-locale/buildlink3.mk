# $NetBSD: buildlink3.mk,v 1.8 2023/11/02 06:36:49 pho Exp $

BUILDLINK_TREE+=	hs-old-locale

.if !defined(HS_OLD_LOCALE_BUILDLINK3_MK)
HS_OLD_LOCALE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-old-locale+=	hs-old-locale>=1.0.0
BUILDLINK_ABI_DEPENDS.hs-old-locale+=	hs-old-locale>=1.0.0.7nb7
BUILDLINK_PKGSRCDIR.hs-old-locale?=	../../devel/hs-old-locale
.endif	# HS_OLD_LOCALE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-old-locale
