# $NetBSD: buildlink3.mk,v 1.6 2021/12/08 16:02:18 adam Exp $

BUILDLINK_TREE+=	rakudo

.if !defined(RAKUDO_BUILDLINK3_MK)
RAKUDO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rakudo+=		rakudo>=2020.02
BUILDLINK_ABI_DEPENDS.rakudo+=		rakudo>=2021.09
BUILDLINK_PKGSRCDIR.rakudo?=		../../lang/rakudo

.include "../../lang/nqp/buildlink3.mk"
.endif # RAKUDO_BUILDLINK3_MK

BUILDLINK_TREE+=	-rakudo
