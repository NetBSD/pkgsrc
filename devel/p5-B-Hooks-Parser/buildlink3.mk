# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:25 joerg Exp $

BUILDLINK_DEPMETHOD.p5-B-Hooks-Parser?=	build

BUILDLINK_TREE+=	p5-B-Hooks-Parser

.if !defined(P5_B_HOOKS_PARSER_BUILDLINK3_MK)
P5_B_HOOKS_PARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-B-Hooks-Parser+=	p5-B-Hooks-Parser>=0.08
BUILDLINK_PKGSRCDIR.p5-B-Hooks-Parser?=	../../devel/p5-B-Hooks-Parser
.endif # P5_B_HOOKS_PARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-B-Hooks-Parser
