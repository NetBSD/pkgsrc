# $NetBSD: buildlink3.mk,v 1.1 2015/04/19 17:29:21 rodent Exp $

BUILDLINK_TREE+=	libsbsms

.if !defined(LIBSBSMS_BUILDLINK3_MK)
LIBSBSMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsbsms+=	libsbsms>=2.0.2
BUILDLINK_PKGSRCDIR.libsbsms?=	../../audio/libsbsms
.endif	# LIBSBSMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsbsms
