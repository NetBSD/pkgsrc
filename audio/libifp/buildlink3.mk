# $NetBSD: buildlink3.mk,v 1.3 2018/02/10 13:53:46 khorben Exp $

BUILDLINK_TREE+=	libifp

.if !defined(LIBIFP_BUILDLINK3_MK)
LIBIFP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libifp+=	libifp>=1.0.0.2
BUILDLINK_PKGSRCDIR.libifp?=	../../audio/libifp

.include "../../mk/libusb.buildlink3.mk"
.endif	# LIBIFP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libifp
