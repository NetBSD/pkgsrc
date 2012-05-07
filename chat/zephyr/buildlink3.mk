# $NetBSD: buildlink3.mk,v 1.9 2012/05/07 01:53:17 dholland Exp $

BUILDLINK_TREE+=	zephyr

.if !defined(ZEPHYR_BUILDLINK3_MK)
ZEPHYR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zephyr+=	zephyr>=20010518nb1
BUILDLINK_ABI_DEPENDS.zephyr+=	zephyr>=20010518nb4
BUILDLINK_PKGSRCDIR.zephyr?=	../../chat/zephyr
BUILDLINK_DEPMETHOD.zephyr?=	build
.endif # ZEPHYR_BUILDLINK3_MK

BUILDLINK_TREE+=	-zephyr
