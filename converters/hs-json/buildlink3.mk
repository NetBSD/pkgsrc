# $NetBSD: buildlink3.mk,v 1.10 2026/11/13 14:38:42 pho Exp $

BUILDLINK_TREE+=	hs-json

.if !defined(HS_JSON_BUILDLINK3_MK)
HS_JSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-json+=	hs-json>=0.11
BUILDLINK_ABI_DEPENDS.hs-json+=	hs-json>=0.11nb6
BUILDLINK_PKGSRCDIR.hs-json?=	../../converters/hs-json

.include "../../devel/hs-syb/buildlink3.mk"
.endif	# HS_JSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-json
