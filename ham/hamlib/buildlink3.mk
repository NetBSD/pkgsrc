# $NetBSD: buildlink3.mk,v 1.13 2023/08/14 05:24:39 wiz Exp $

BUILDLINK_TREE+=	hamlib

.if !defined(HAMLIB_BUILDLINK3_MK)
HAMLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hamlib+=	hamlib>=1.1.4
BUILDLINK_ABI_DEPENDS.hamlib+=	hamlib>=4.5.5nb1
BUILDLINK_PKGSRCDIR.hamlib?=	../../ham/hamlib

.include "../../devel/libusb1/buildlink3.mk"
.endif # HAMLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hamlib
