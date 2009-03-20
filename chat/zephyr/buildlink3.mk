# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:02 joerg Exp $

BUILDLINK_TREE+=	zephyr

.if !defined(ZEPHYR_BUILDLINK3_MK)
ZEPHYR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zephyr+=	zephyr>=20010518nb1
BUILDLINK_ABI_DEPENDS.zephyr?=	zephyr>=20010518nb4
BUILDLINK_PKGSRCDIR.zephyr?=	../../chat/zephyr
BUILDLINK_DEPMETHOD.zephyr?=	build
.endif # ZEPHYR_BUILDLINK3_MK

BUILDLINK_TREE+=	-zephyr
