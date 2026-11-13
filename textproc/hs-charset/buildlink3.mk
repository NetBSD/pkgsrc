# $NetBSD: buildlink3.mk,v 1.12 2026/11/13 14:39:49 pho Exp $

BUILDLINK_TREE+=	hs-charset

.if !defined(HS_CHARSET_BUILDLINK3_MK)
HS_CHARSET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-charset+=	hs-charset>=0.3.11
BUILDLINK_ABI_DEPENDS.hs-charset+=	hs-charset>=0.3.11nb4
BUILDLINK_PKGSRCDIR.hs-charset?=	../../textproc/hs-charset

.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_CHARSET_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-charset
