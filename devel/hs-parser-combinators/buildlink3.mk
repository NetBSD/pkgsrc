# $NetBSD: buildlink3.mk,v 1.10 2024/05/09 01:32:07 pho Exp $

BUILDLINK_TREE+=	hs-parser-combinators

.if !defined(HS_PARSER_COMBINATORS_BUILDLINK3_MK)
HS_PARSER_COMBINATORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-parser-combinators+=	hs-parser-combinators>=1.3.0
BUILDLINK_ABI_DEPENDS.hs-parser-combinators+=	hs-parser-combinators>=1.3.0nb8
BUILDLINK_PKGSRCDIR.hs-parser-combinators?=	../../devel/hs-parser-combinators
.endif	# HS_PARSER_COMBINATORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-parser-combinators
