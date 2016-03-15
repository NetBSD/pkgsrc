# $NetBSD: buildlink3.mk,v 1.9 2016/03/15 13:45:17 szptvlfn Exp $

BUILDLINK_TREE+=	hs-tagsoup

.if !defined(HS_TAGSOUP_BUILDLINK3_MK)
HS_TAGSOUP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagsoup+=	hs-tagsoup>=0.13.9
BUILDLINK_ABI_DEPENDS.hs-tagsoup+=	hs-tagsoup>=0.13.9
BUILDLINK_PKGSRCDIR.hs-tagsoup?=	../../textproc/hs-tagsoup

.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_TAGSOUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagsoup
