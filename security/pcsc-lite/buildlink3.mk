# $NetBSD: buildlink3.mk,v 1.6 2013/01/08 22:51:39 pettai Exp $

BUILDLINK_TREE+=	pcsc-lite

.if !defined(PCSC_LITE_BUILDLINK3_MK)
PCSC_LITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pcsc-lite+=	pcsc-lite>=1.6.5
BUILDLINK_PKGSRCDIR.pcsc-lite?=	../../security/pcsc-lite

.include "../../devel/libusb1/buildlink3.mk"
.endif # PCSC_LITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-pcsc-lite
