# $NetBSD: buildlink3.mk,v 1.5 2022/06/28 11:31:55 wiz Exp $

BUILDLINK_TREE+=	p5-B-Hooks-Parser

.if !defined(P5_B_HOOKS_PARSER_BUILDLINK3_MK)
P5_B_HOOKS_PARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-B-Hooks-Parser+=	p5-B-Hooks-Parser>=0.08
BUILDLINK_ABI_DEPENDS.p5-B-Hooks-Parser?=		p5-B-Hooks-Parser>=0.21nb4
BUILDLINK_PKGSRCDIR.p5-B-Hooks-Parser?=		../../devel/p5-B-Hooks-Parser
.endif # P5_B_HOOKS_PARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-B-Hooks-Parser
