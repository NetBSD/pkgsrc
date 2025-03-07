# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 18:34:10 pho Exp $

BUILDLINK_TREE+=	hs-raw-strings-qq

.if !defined(HS_RAW_STRINGS_QQ_BUILDLINK3_MK)
HS_RAW_STRINGS_QQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-raw-strings-qq+=	hs-raw-strings-qq>=1.1
BUILDLINK_ABI_DEPENDS.hs-raw-strings-qq+=	hs-raw-strings-qq>=1.1
BUILDLINK_PKGSRCDIR.hs-raw-strings-qq?=		../../devel/hs-raw-strings-qq

.endif	# HS_RAW_STRINGS_QQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-raw-strings-qq
