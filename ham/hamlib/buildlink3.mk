# $NetBSD: buildlink3.mk,v 1.10 2018/06/06 22:45:58 gdt Exp $

BUILDLINK_TREE+=	hamlib

.if !defined(HAMLIB_BUILDLINK3_MK)
HAMLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hamlib+=	hamlib>=1.1.4
BUILDLINK_ABI_DEPENDS.hamlib+=	hamlib>=1.2.5
BUILDLINK_PKGSRCDIR.hamlib?=	../../ham/hamlib
.endif # HAMLIB_BUILDLINK3_MK

.include "../../devel/libusb1/buildlink3.mk"

BUILDLINK_TREE+=	-hamlib
