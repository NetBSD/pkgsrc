# $NetBSD: buildlink3.mk,v 1.8 2025/08/20 19:22:52 wiz Exp $

BUILDLINK_TREE+=	happy-lib

.if !defined(HAPPY_LIB_BUILDLINK3_MK)
HAPPY_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.happy-lib+=	happy-lib>=2.1.7
BUILDLINK_ABI_DEPENDS.happy-lib+=	happy-lib>=2.1.7
BUILDLINK_PKGSRCDIR.happy-lib?=		../../devel/happy-lib
.endif	# HAPPY_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-happy-lib
