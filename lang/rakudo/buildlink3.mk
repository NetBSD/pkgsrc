# $NetBSD: buildlink3.mk,v 1.7 2022/06/08 12:46:35 mef Exp $

BUILDLINK_TREE+=	rakudo

.if !defined(RAKUDO_BUILDLINK3_MK)
RAKUDO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rakudo+=		rakudo>=2022.06
BUILDLINK_ABI_DEPENDS.rakudo+=		rakudo>=2022.06
BUILDLINK_PKGSRCDIR.rakudo?=		../../lang/rakudo

.include "../../lang/nqp/buildlink3.mk"
.endif # RAKUDO_BUILDLINK3_MK

BUILDLINK_TREE+=	-rakudo
