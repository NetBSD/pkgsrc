# $NetBSD: buildlink3.mk,v 1.2 2018/02/10 13:53:47 khorben Exp $

BUILDLINK_TREE+=	libnfc

.if !defined(LIBNFC_BUILDLINK3_MK)
LIBNFC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnfc+=	libnfc>=1.7.1
BUILDLINK_ABI_DEPENDS.libnfc+=	libnfc>=1.7.1
BUILDLINK_PKGSRCDIR.libnfc?=	../../devel/libnfc

.include "../../mk/libusb.buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/pcsc-lite/buildlink3.mk"
.endif # LIBNFC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnfc
