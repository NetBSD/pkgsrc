# $NetBSD: buildlink3.mk,v 1.3 2021/05/03 19:01:01 pho Exp $

BUILDLINK_TREE+=	hs-pretty-show

.if !defined(HS_PRETTY_SHOW_BUILDLINK3_MK)
HS_PRETTY_SHOW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pretty-show+=	hs-pretty-show>=1.10
BUILDLINK_ABI_DEPENDS.hs-pretty-show+=	hs-pretty-show>=1.10nb1
BUILDLINK_PKGSRCDIR.hs-pretty-show?=	../../devel/hs-pretty-show

.include "../../devel/hs-haskell-lexer/buildlink3.mk"
.endif	# HS_PRETTY_SHOW_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pretty-show
