# $NetBSD: buildlink3.mk,v 1.3 2018/02/10 13:53:47 khorben Exp $

BUILDLINK_TREE+=	libnjb

.if !defined(LIBNJB_BUILDLINK3_MK)
LIBNJB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnjb+=	libnjb>=2.2.6
BUILDLINK_PKGSRCDIR.libnjb?=	../../devel/libnjb

.include "../../mk/libusb.buildlink3.mk"
.endif # LIBNJB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnjb
