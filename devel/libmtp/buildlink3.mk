# $NetBSD: buildlink3.mk,v 1.5 2016/04/09 10:09:14 richard Exp $

BUILDLINK_TREE+=	libmtp

.if !defined(LIBMTP_BUILDLINK3_MK)
LIBMTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmtp+=	libmtp>=0.3.0
BUILDLINK_PKGSRCDIR.libmtp?=	../../devel/libmtp

.include "../../mk/bsd.fast.prefs.mk"

.include "../../devel/libusb1/buildlink3.mk"

.endif # LIBMTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmtp
