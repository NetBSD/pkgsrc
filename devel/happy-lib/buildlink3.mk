# $NetBSD: buildlink3.mk,v 1.6 2025/07/20 10:14:38 wiz Exp $

BUILDLINK_TREE+=	happy-lib

.if !defined(HAPPY_LIB_BUILDLINK3_MK)
HAPPY_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.happy-lib+=	happy-lib>=2.1.6
BUILDLINK_ABI_DEPENDS.happy-lib+=	happy-lib>=2.1.6
BUILDLINK_PKGSRCDIR.happy-lib?=		../../devel/happy-lib
.endif	# HAPPY_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-happy-lib
