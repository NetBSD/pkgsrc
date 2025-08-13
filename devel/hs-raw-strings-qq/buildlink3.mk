# $NetBSD: buildlink3.mk,v 1.2 2025/08/13 11:06:54 pho Exp $

BUILDLINK_TREE+=	hs-raw-strings-qq

.if !defined(HS_RAW_STRINGS_QQ_BUILDLINK3_MK)
HS_RAW_STRINGS_QQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-raw-strings-qq+=	hs-raw-strings-qq>=1.1
BUILDLINK_ABI_DEPENDS.hs-raw-strings-qq+=	hs-raw-strings-qq>=1.1nb1
BUILDLINK_PKGSRCDIR.hs-raw-strings-qq?=		../../devel/hs-raw-strings-qq

.endif	# HS_RAW_STRINGS_QQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-raw-strings-qq
