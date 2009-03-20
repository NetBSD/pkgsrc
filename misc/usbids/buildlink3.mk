# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:01 joerg Exp $

BUILDLINK_TREE+=	usbids

.if !defined(USBIDS_BUILDLINK3_MK)
USBIDS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.usbids+=	usbids>=20081118
BUILDLINK_PKGSRCDIR.usbids?=	../../misc/usbids
.endif # USBIDS_BUILDLINK3_MK

BUILDLINK_TREE+=	-usbids
