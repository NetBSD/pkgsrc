# $NetBSD: buildlink3.mk,v 1.10 2023/11/02 06:37:26 pho Exp $

BUILDLINK_TREE+=	hs-Glob

.if !defined(HS_GLOB_BUILDLINK3_MK)
HS_GLOB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Glob+=	hs-Glob>=0.10.2
BUILDLINK_ABI_DEPENDS.hs-Glob+=	hs-Glob>=0.10.2nb5
BUILDLINK_PKGSRCDIR.hs-Glob?=	../../textproc/hs-Glob

.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_GLOB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Glob
