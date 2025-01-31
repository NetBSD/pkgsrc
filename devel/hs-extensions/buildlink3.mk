# $NetBSD: buildlink3.mk,v 1.3 2025/01/31 10:46:15 pho Exp $

BUILDLINK_TREE+=	hs-extensions

.if !defined(HS_EXTENSIONS_BUILDLINK3_MK)
HS_EXTENSIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-extensions+=	hs-extensions>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-extensions+=	hs-extensions>=0.1.0.2
BUILDLINK_PKGSRCDIR.hs-extensions?=	../../devel/hs-extensions
.endif	# HS_EXTENSIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-extensions
