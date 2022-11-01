# $NetBSD: buildlink3.mk,v 1.12 2022/11/01 17:23:45 gdt Exp $

BUILDLINK_TREE+=	hamlib

.if !defined(HAMLIB_BUILDLINK3_MK)
HAMLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hamlib+=	hamlib>=1.1.4
BUILDLINK_ABI_DEPENDS.hamlib+=	hamlib>=4.3.1nb1
BUILDLINK_PKGSRCDIR.hamlib?=	../../ham/hamlib

.include "../../devel/libusb1/buildlink3.mk"
.endif # HAMLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hamlib
