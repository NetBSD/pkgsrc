# $NetBSD: buildlink3.mk,v 1.6 2016/04/11 19:01:35 ryoon Exp $

BUILDLINK_TREE+=	rakudo-star

.if !defined(RAKUDO_STAR_BUILDLINK3_MK)
RAKUDO_STAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rakudo-star+=		rakudo-star>=2013.08
BUILDLINK_ABI_DEPENDS.rakudo-star+=		rakudo-star>=2013.08nb8
BUILDLINK_PKGSRCDIR.rakudo-star?=		../../lang/rakudo-star

.include "../../lang/nqp/buildlink3.mk"
.endif # RAKUDO_STAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-rakudo-star
