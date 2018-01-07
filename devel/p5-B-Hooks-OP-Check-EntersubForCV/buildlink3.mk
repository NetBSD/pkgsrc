# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:09 rillig Exp $

BUILDLINK_TREE+=	p5-B-Hooks-OP-Check-EntersubForCV

.if !defined(P5_B_HOOKS_OP_CHECK_ENTERSUBFORCV_BUILDLINK3_MK)
P5_B_HOOKS_OP_CHECK_ENTERSUBFORCV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-B-Hooks-OP-Check-EntersubForCV+=	p5-B-Hooks-OP-Check-EntersubForCV>=0.08
BUILDLINK_PKGSRCDIR.p5-B-Hooks-OP-Check-EntersubForCV?=		../../devel/p5-B-Hooks-OP-Check-EntersubForCV
.endif # P5_B_HOOKS_OP_CHECK_ENTERSUBFORCV_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-B-Hooks-OP-Check-EntersubForCV
