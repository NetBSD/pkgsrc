# $NetBSD: buildlink3.mk,v 1.5 2025/03/05 03:39:00 pho Exp $

BUILDLINK_TREE+=	happy-lib

.if !defined(HAPPY_LIB_BUILDLINK3_MK)
HAPPY_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.happy-lib+=	happy-lib>=2.1.5
BUILDLINK_ABI_DEPENDS.happy-lib+=	happy-lib>=2.1.5nb1
BUILDLINK_PKGSRCDIR.happy-lib?=		../../devel/happy-lib
.endif	# HAPPY_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-happy-lib
