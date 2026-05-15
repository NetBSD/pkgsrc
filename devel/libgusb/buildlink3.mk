# $NetBSD: buildlink3.mk,v 1.2 2026/05/15 20:08:42 wiz Exp $

BUILDLINK_TREE+=	libgusb

.if !defined(LIBGUSB_BUILDLINK3_MK)
LIBGUSB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgusb+=	libgusb>=0.4.9
BUILDLINK_PKGSRCDIR.libgusb?=	../../devel/libgusb

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../sysutils/hwdata/buildlink3.mk"
.endif	# LIBGUSB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgusb
