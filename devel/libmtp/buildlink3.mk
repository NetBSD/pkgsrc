# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:20 joerg Exp $

BUILDLINK_TREE+=	libmtp

.if !defined(LIBMTP_BUILDLINK3_MK)
LIBMTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmtp+=	libmtp>=0.3.0
BUILDLINK_PKGSRCDIR.libmtp?=	../../devel/libmtp

.include "../../devel/libusb/buildlink3.mk"
.endif # LIBMTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmtp
