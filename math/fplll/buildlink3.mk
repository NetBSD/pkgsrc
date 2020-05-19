# $NetBSD: buildlink3.mk,v 1.1 2020/05/19 14:44:42 riastradh Exp $

BUILDLINK_TREE+=	fplll

.if !defined(FPLLL_BUILDLINK3_MK)
FPLLL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fplll+=	fplll>=5.3.2
BUILDLINK_PKGSRCDIR.fplll?=	../../math/fplll

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.endif	# FPLLL_BUILDLINK3_MK

BUILDLINK_TREE+=	-fplll
