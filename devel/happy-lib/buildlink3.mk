# $NetBSD: buildlink3.mk,v 1.10 2026/11/13 14:38:44 pho Exp $

BUILDLINK_TREE+=	happy-lib

.if !defined(HAPPY_LIB_BUILDLINK3_MK)
HAPPY_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.happy-lib+=	happy-lib>=2.2
BUILDLINK_ABI_DEPENDS.happy-lib+=	happy-lib>=2.2nb1
BUILDLINK_PKGSRCDIR.happy-lib?=		../../devel/happy-lib
.endif	# HAPPY_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-happy-lib
