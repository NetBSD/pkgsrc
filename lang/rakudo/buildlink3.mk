# $NetBSD: buildlink3.mk,v 1.2 2018/04/29 20:53:39 adam Exp $

BUILDLINK_TREE+=	rakudo

.if !defined(RAKUDO_BUILDLINK3_MK)
RAKUDO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rakudo+=		rakudo>=2017.09
BUILDLINK_ABI_DEPENDS.rakudo+=		rakudo>=2017.09
BUILDLINK_PKGSRCDIR.rakudo?=		../../lang/rakudo

.include "../../lang/nqp/buildlink3.mk"
.endif # RAKUDO_BUILDLINK3_MK

BUILDLINK_TREE+=	-rakudo
