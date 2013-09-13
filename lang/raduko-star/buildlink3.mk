# $NetBSD: buildlink3.mk,v 1.1 2013/09/13 12:09:39 sno Exp $

BUILDLINK_TREE+=	raduko-star

.if !defined(RADUKO_STAR_BUILDLINK3_MK)
RADUKO_STAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.raduko-star+=		raduko-star>=2013.08
BUILDLINK_ABI_DEPENDS.raduko-star+=		raduko-star>=2013.08
BUILDLINK_PKGSRCDIR.raduko-star?=		../../lang/raduko-star

.include "../../lang/nqp/buildlink3.mk"
.endif # RADUKO_STAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-raduko-star
