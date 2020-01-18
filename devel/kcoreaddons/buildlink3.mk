# $NetBSD: buildlink3.mk,v 1.14 2020/01/18 21:48:04 jperkin Exp $

BUILDLINK_TREE+=	kcoreaddons

.if !defined(KCOREADDONS_BUILDLINK3_MK)
KCOREADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcoreaddons+=	kcoreaddons>=5.18.0
BUILDLINK_ABI_DEPENDS.kcoreaddons?=	kcoreaddons>=5.64.0nb1
BUILDLINK_PKGSRCDIR.kcoreaddons?=	../../devel/kcoreaddons

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCOREADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcoreaddons
