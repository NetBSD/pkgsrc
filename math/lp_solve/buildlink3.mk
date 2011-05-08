# $NetBSD: buildlink3.mk,v 1.1 2011/05/08 11:52:40 wiz Exp $

BUILDLINK_TREE+=	lp_solve

.if !defined(LP_SOLVE_BUILDLINK3_MK)
LP_SOLVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lp_solve+=	lp_solve>=5.5.2.0
BUILDLINK_PKGSRCDIR.lp_solve?=	../../math/lp_solve
.endif	# LP_SOLVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-lp_solve
