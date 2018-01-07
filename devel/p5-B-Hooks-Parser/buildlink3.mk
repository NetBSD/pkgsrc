# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:04:09 rillig Exp $

BUILDLINK_TREE+=	p5-B-Hooks-Parser

.if !defined(P5_B_HOOKS_PARSER_BUILDLINK3_MK)
P5_B_HOOKS_PARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-B-Hooks-Parser+=	p5-B-Hooks-Parser>=0.08
BUILDLINK_PKGSRCDIR.p5-B-Hooks-Parser?=		../../devel/p5-B-Hooks-Parser
.endif # P5_B_HOOKS_PARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-B-Hooks-Parser
