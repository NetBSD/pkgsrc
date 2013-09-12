# $NetBSD: buildlink3.mk,v 1.1 2013/09/12 14:04:41 ryoon Exp $

BUILDLINK_TREE+=	cross-freemint-gemlib

.if !defined(CROSS_FREEMINT_GEMLIB_BUILDLINK3_MK)
CROSS_FREEMINT_GEMLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cross-freemint-gemlib+=	cross-freemint-gemlib>=20130415
BUILDLINK_PKGSRCDIR.cross-freemint-gemlib?=	../../cross/freemint-gemlib

.endif	# CROSS_FREEMINT_GEMLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-cross-freemint-gemlib
