# $NetBSD: buildlink3.mk,v 1.1 2020/01/17 17:24:36 pho Exp $

BUILDLINK_TREE+=	hs-pretty-show

.if !defined(HS_PRETTY_SHOW_BUILDLINK3_MK)
HS_PRETTY_SHOW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pretty-show+=	hs-pretty-show>=1.9.5
BUILDLINK_ABI_DEPENDS.hs-pretty-show+=	hs-pretty-show>=1.9.5
BUILDLINK_PKGSRCDIR.hs-pretty-show?=	../../devel/hs-pretty-show

.include "../../devel/hs-haskell-lexer/buildlink3.mk"
.endif	# HS_PRETTY_SHOW_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pretty-show
