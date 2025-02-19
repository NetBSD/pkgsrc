# $NetBSD: buildlink3.mk,v 1.4 2025/02/19 13:26:19 wiz Exp $

BUILDLINK_TREE+=	happy-lib

.if !defined(HAPPY_LIB_BUILDLINK3_MK)
HAPPY_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.happy-lib+=	happy-lib>=2.1.5
BUILDLINK_ABI_DEPENDS.happy-lib+=	happy-lib>=2.1.5
BUILDLINK_PKGSRCDIR.happy-lib?=		../../devel/happy-lib
.endif	# HAPPY_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-happy-lib
