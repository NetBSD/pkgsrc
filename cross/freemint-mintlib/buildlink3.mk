# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:31:14 wiz Exp $

BUILDLINK_TREE+=	cross-freemint-mintlib

.if !defined(CROSS_FREEMINT_MINTLIB_BUILDLINK3_MK)
CROSS_FREEMINT_MINTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cross-freemint-mintlib+=	cross-freemint-mintlib>=20130415
BUILDLINK_ABI_DEPENDS.cross-freemint-mintlib?=	cross-freemint-mintlib>=20131219nb4
BUILDLINK_PKGSRCDIR.cross-freemint-mintlib?=	../../cross/freemint-mintlib

.endif	# CROSS_FREEMINT_MINTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-cross-freemint-mintlib
