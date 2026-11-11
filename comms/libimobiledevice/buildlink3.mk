# $NetBSD: buildlink3.mk,v 1.3 2026/11/11 11:52:06 wiz Exp $

BUILDLINK_TREE+=	libimobiledevice

.if !defined(LIBIMOBILEDEVICE_BUILDLINK3_MK)
LIBIMOBILEDEVICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libimobiledevice+=	libimobiledevice>=1.2.0
BUILDLINK_ABI_DEPENDS.libimobiledevice+=	libimobiledevice>=1.4.0nb3
BUILDLINK_PKGSRCDIR.libimobiledevice?=		../../comms/libimobiledevice

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../security/libtatsu/buildlink3.mk"
.include "../../comms/libusbmuxd/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # LIBIMOBILEDEVICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libimobiledevice
