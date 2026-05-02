# $NetBSD: buildlink3.mk,v 1.1 2026/05/02 07:01:14 vins Exp $

BUILDLINK_TREE+=	libimobiledevice

.if !defined(LIBIMOBILEDEVICE_BUILDLINK3_MK)
LIBIMOBILEDEVICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libimobiledevice+=	libimobiledevice>=1.2.0
BUILDLINK_ABI_DEPENDS.libimobiledevice+=	libimobiledevice>=1.2.0
BUILDLINK_PKGSRCDIR.libimobiledevice?=		../../comms/libimobiledevice

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../security/libtatsu/buildlink3.mk"
.include "../../comms/libusbmuxd/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # LIBIMOBILEDEVICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libimobiledevice
