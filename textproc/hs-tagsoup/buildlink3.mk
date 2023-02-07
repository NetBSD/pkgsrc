# $NetBSD: buildlink3.mk,v 1.16 2023/02/07 01:41:14 pho Exp $

BUILDLINK_TREE+=	hs-tagsoup

.if !defined(HS_TAGSOUP_BUILDLINK3_MK)
HS_TAGSOUP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagsoup+=	hs-tagsoup>=0.14.8
BUILDLINK_ABI_DEPENDS.hs-tagsoup+=	hs-tagsoup>=0.14.8nb5
BUILDLINK_PKGSRCDIR.hs-tagsoup?=	../../textproc/hs-tagsoup
.endif	# HS_TAGSOUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagsoup
