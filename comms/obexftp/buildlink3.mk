# $NetBSD: buildlink3.mk,v 1.4 2018/02/10 13:53:47 khorben Exp $

BUILDLINK_TREE+=	obexftp

.if !defined(OBEXFTP_BUILDLINK3_MK)
OBEXFTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.obexftp+=	obexftp>=0.24
BUILDLINK_PKGSRCDIR.obexftp?=	../../comms/obexftp

.include "../../comms/openobex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/libusb.buildlink3.mk"
.endif # OBEXFTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-obexftp
