# $NetBSD: buildlink3.mk,v 1.3 2009/10/19 10:14:52 abs Exp $

BUILDLINK_TREE+=	p5-B-Hooks-Parser

.if !defined(P5_B_HOOKS_PARSER_BUILDLINK3_MK)
P5_B_HOOKS_PARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-B-Hooks-Parser+=	p5-B-Hooks-Parser>=0.08
BUILDLINK_PKGSRCDIR.p5-B-Hooks-Parser?=	../../devel/p5-B-Hooks-Parser
.endif # P5_B_HOOKS_PARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-B-Hooks-Parser
