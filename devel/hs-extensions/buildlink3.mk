# $NetBSD: buildlink3.mk,v 1.2 2024/05/09 01:31:53 pho Exp $

BUILDLINK_TREE+=	hs-extensions

.if !defined(HS_EXTENSIONS_BUILDLINK3_MK)
HS_EXTENSIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-extensions+=	hs-extensions>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-extensions+=	hs-extensions>=0.1.0.1nb1
BUILDLINK_PKGSRCDIR.hs-extensions?=	../../devel/hs-extensions
.endif	# HS_EXTENSIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-extensions
