# $NetBSD: buildlink3.mk,v 1.4 2022/02/12 08:50:36 pho Exp $

BUILDLINK_TREE+=	hs-old-locale

.if !defined(HS_OLD_LOCALE_BUILDLINK3_MK)
HS_OLD_LOCALE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-old-locale+=	hs-old-locale>=1.0.0
BUILDLINK_ABI_DEPENDS.hs-old-locale+=	hs-old-locale>=1.0.0.7nb3
BUILDLINK_PKGSRCDIR.hs-old-locale?=	../../devel/hs-old-locale
.endif	# HS_OLD_LOCALE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-old-locale
