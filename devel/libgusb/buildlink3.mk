# $NetBSD: buildlink3.mk,v 1.5 2026/09/29 06:04:34 wiz Exp $

BUILDLINK_TREE+=	libgusb

.if !defined(LIBGUSB_BUILDLINK3_MK)
LIBGUSB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgusb+=	libgusb>=0.4.9
BUILDLINK_ABI_DEPENDS.libgusb?=	libgusb>=0.4.9nb3
BUILDLINK_PKGSRCDIR.libgusb?=	../../devel/libgusb

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../sysutils/hwdata/buildlink3.mk"
.endif	# LIBGUSB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgusb
