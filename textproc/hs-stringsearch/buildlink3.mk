# $NetBSD: buildlink3.mk,v 1.6 2022/02/12 08:50:55 pho Exp $

BUILDLINK_TREE+=	hs-stringsearch

.if !defined(HS_STRINGSEARCH_BUILDLINK3_MK)
HS_STRINGSEARCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-stringsearch+=	hs-stringsearch>=0.3.6
BUILDLINK_ABI_DEPENDS.hs-stringsearch+=	hs-stringsearch>=0.3.6.6nb3
BUILDLINK_PKGSRCDIR.hs-stringsearch?=	../../textproc/hs-stringsearch
.endif	# HS_STRINGSEARCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-stringsearch
