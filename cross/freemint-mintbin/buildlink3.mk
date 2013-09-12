# $NetBSD: buildlink3.mk,v 1.1 2013/09/12 14:00:30 ryoon Exp $

BUILDLINK_DEPMETHOD.cross-freemint-mintbin?=	build

BUILDLINK_TREE+=	cross-freemint-mintbin

.if !defined(CROSS_FREEMINT_MINTBIN_BUILDLINK3_MK)
CROSS_FREEMINT_MINTBIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cross-freemint-mintbin+=	cross-freemint-mintbin>=20110527
BUILDLINK_PKGSRCDIR.cross-freemint-mintbin?=	../../cross/freemint-mintbin
.endif	# CROSS_FREEMINT_MINTBIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-cross-freemint-mintbin
