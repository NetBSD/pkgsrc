# $NetBSD: buildlink3.mk,v 1.4 2022/06/28 11:31:55 wiz Exp $

BUILDLINK_TREE+=	p5-B-Hooks-OP-Check

.if !defined(P5_B_HOOKS_OP_CHECK_BUILDLINK3_MK)
P5_B_HOOKS_OP_CHECK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-B-Hooks-OP-Check+=	p5-B-Hooks-OP-Check>=0.12nb1
BUILDLINK_ABI_DEPENDS.p5-B-Hooks-OP-Check?=	p5-B-Hooks-OP-Check>=0.22nb5
BUILDLINK_PKGSRCDIR.p5-B-Hooks-OP-Check?=	../../devel/p5-B-Hooks-OP-Check
.endif # P5_B_HOOKS_OP_CHECK_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-B-Hooks-OP-Check
