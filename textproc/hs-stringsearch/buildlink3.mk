# $NetBSD: buildlink3.mk,v 1.11 2024/05/09 01:32:47 pho Exp $

BUILDLINK_TREE+=	hs-stringsearch

.if !defined(HS_STRINGSEARCH_BUILDLINK3_MK)
HS_STRINGSEARCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stringsearch+=	hs-stringsearch>=0.3.6
BUILDLINK_ABI_DEPENDS.hs-stringsearch+=	hs-stringsearch>=0.3.6.6nb8
BUILDLINK_PKGSRCDIR.hs-stringsearch?=	../../textproc/hs-stringsearch
.endif	# HS_STRINGSEARCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stringsearch
