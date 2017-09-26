# $NetBSD: buildlink3.mk,v 1.1 2017/09/26 17:23:05 mspo Exp $

BUILDLINK_TREE+=	rakudo

.if !defined(RAKUDO_BUILDLINK3_MK)
RAKUDO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rakudo+=		rakudo>=2017.09
BUILDLINK_ABI_DEPENDS.rakudo+=		rakudo>=2017.09
BUILDLINK_PKGSRCDIR.rakudo?=		../../wip/rakudo

.include "../../wip/nqp/buildlink3.mk"
.endif # RAKUDO_BUILDLINK3_MK

BUILDLINK_TREE+=	-rakudo
