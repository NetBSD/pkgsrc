# $NetBSD: buildlink3.mk,v 1.1 2024/05/05 05:49:50 pho Exp $

BUILDLINK_TREE+=	hs-extensions

.if !defined(HS_EXTENSIONS_BUILDLINK3_MK)
HS_EXTENSIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-extensions+=	hs-extensions>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-extensions+=	hs-extensions>=0.1.0.1
BUILDLINK_PKGSRCDIR.hs-extensions?=	../../devel/hs-extensions
.endif	# HS_EXTENSIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-extensions
