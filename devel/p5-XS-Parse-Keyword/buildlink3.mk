# $NetBSD: buildlink3.mk,v 1.1 2024/07/07 19:52:32 wiz Exp $

BUILDLINK_TREE+=	p5-XS-Parse-Keyword

.if !defined(P5_XS_PARSE_KEYWORD_BUILDLINK3_MK)
P5_XS_PARSE_KEYWORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-XS-Parse-Keyword+=	p5-XS-Parse-Keyword>=0.43
BUILDLINK_PKGSRCDIR.p5-XS-Parse-Keyword?=	../../devel/p5-XS-Parse-Keyword
.endif	# P5_XS_PARSE_KEYWORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-XS-Parse-Keyword
