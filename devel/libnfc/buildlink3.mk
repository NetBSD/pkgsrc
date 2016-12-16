# $NetBSD: buildlink3.mk,v 1.1 2016/12/16 08:11:55 manu Exp $

BUILDLINK_TREE+=	libnfc

.if !defined(LIBNFC_BUILDLINK3_MK)
LIBNFC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnfc+=	libnfc>=1.7.1
BUILDLINK_ABI_DEPENDS.libnfc+=	libnfc>=1.7.1
BUILDLINK_PKGSRCDIR.libnfc?=	../../devel/libnfc

.include "../../devel/libusb/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/pcsc-lite/buildlink3.mk"
.endif # LIBNFC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnfc
