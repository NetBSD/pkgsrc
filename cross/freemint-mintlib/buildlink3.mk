# $NetBSD: buildlink3.mk,v 1.1 2013/09/12 14:02:01 ryoon Exp $

BUILDLINK_TREE+=	cross-freemint-mintlib

.if !defined(CROSS_FREEMINT_MINTLIB_BUILDLINK3_MK)
CROSS_FREEMINT_MINTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cross-freemint-mintlib+=	cross-freemint-mintlib>=20130415
BUILDLINK_PKGSRCDIR.cross-freemint-mintlib?=	../../cross/freemint-mintlib

.endif	# CROSS_FREEMINT_MINTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-cross-freemint-mintlib
