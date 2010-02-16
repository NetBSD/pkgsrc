# $NetBSD: buildlink3.mk,v 1.2 2010/02/16 08:57:48 wiz Exp $

BUILDLINK_TREE+=	libifp

.if !defined(LIBIFP_BUILDLINK3_MK)
LIBIFP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libifp+=	libifp>=1.0.0.2
BUILDLINK_PKGSRCDIR.libifp?=	../../audio/libifp

.include "../../devel/libusb/buildlink3.mk"
.endif	# LIBIFP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libifp
