# $NetBSD: buildlink3.mk,v 1.3 2018/10/08 16:54:28 maya Exp $

BUILDLINK_TREE+=	rakudo

.if !defined(RAKUDO_BUILDLINK3_MK)
RAKUDO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rakudo+=		rakudo>=2018.06
BUILDLINK_ABI_DEPENDS.rakudo+=		rakudo>=2018.06
BUILDLINK_PKGSRCDIR.rakudo?=		../../lang/rakudo

.include "../../lang/nqp/buildlink3.mk"
.endif # RAKUDO_BUILDLINK3_MK

BUILDLINK_TREE+=	-rakudo
