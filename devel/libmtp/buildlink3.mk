# $NetBSD: buildlink3.mk,v 1.4 2014/08/21 14:03:45 jperkin Exp $

BUILDLINK_TREE+=	libmtp

.if !defined(LIBMTP_BUILDLINK3_MK)
LIBMTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmtp+=	libmtp>=0.3.0
BUILDLINK_PKGSRCDIR.libmtp?=	../../devel/libmtp

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "SunOS"
.include "../../devel/libusb/buildlink3.mk"
.else
.include "../../devel/libusb1/buildlink3.mk"
.endif

.endif # LIBMTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmtp
