# $NetBSD: buildlink3.mk,v 1.6 2025/08/13 11:06:38 pho Exp $

BUILDLINK_TREE+=	hs-extensions

.if !defined(HS_EXTENSIONS_BUILDLINK3_MK)
HS_EXTENSIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-extensions+=	hs-extensions>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-extensions+=	hs-extensions>=0.1.0.2nb3
BUILDLINK_PKGSRCDIR.hs-extensions?=	../../devel/hs-extensions
.endif	# HS_EXTENSIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-extensions
