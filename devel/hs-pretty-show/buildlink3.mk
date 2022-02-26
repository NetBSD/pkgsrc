# $NetBSD: buildlink3.mk,v 1.6 2022/02/26 03:58:04 pho Exp $

BUILDLINK_TREE+=	hs-pretty-show

.if !defined(HS_PRETTY_SHOW_BUILDLINK3_MK)
HS_PRETTY_SHOW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pretty-show+=	hs-pretty-show>=1.10
BUILDLINK_ABI_DEPENDS.hs-pretty-show+=	hs-pretty-show>=1.10nb4
BUILDLINK_PKGSRCDIR.hs-pretty-show?=	../../devel/hs-pretty-show

.include "../../devel/hs-haskell-lexer/buildlink3.mk"
.endif	# HS_PRETTY_SHOW_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pretty-show
