# $NetBSD: buildlink3.mk,v 1.4 2026/09/27 11:35:42 tnn Exp $

BUILDLINK_TREE+=	libgusb

.if !defined(LIBGUSB_BUILDLINK3_MK)
LIBGUSB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgusb+=	libgusb>=0.4.9
BUILDLINK_ABI_DEPENDS.libgusb?=	libgusb>=0.4.9nb2
BUILDLINK_PKGSRCDIR.libgusb?=	../../devel/libgusb

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../sysutils/hwdata/buildlink3.mk"
.endif	# LIBGUSB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgusb
