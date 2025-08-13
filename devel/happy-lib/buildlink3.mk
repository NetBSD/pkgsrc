# $NetBSD: buildlink3.mk,v 1.7 2025/08/13 11:06:27 pho Exp $

BUILDLINK_TREE+=	happy-lib

.if !defined(HAPPY_LIB_BUILDLINK3_MK)
HAPPY_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.happy-lib+=	happy-lib>=2.1.6
BUILDLINK_ABI_DEPENDS.happy-lib+=	happy-lib>=2.1.6nb2
BUILDLINK_PKGSRCDIR.happy-lib?=		../../devel/happy-lib
.endif	# HAPPY_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-happy-lib
