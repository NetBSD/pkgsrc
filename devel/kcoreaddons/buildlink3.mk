# $NetBSD: buildlink3.mk,v 1.27 2023/04/19 08:08:13 adam Exp $

BUILDLINK_TREE+=	kcoreaddons

.if !defined(KCOREADDONS_BUILDLINK3_MK)
KCOREADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcoreaddons+=	kcoreaddons>=5.18.0
BUILDLINK_ABI_DEPENDS.kcoreaddons?=	kcoreaddons>=5.98.0nb4
BUILDLINK_PKGSRCDIR.kcoreaddons?=	../../devel/kcoreaddons

BUILDLINK_FILES.kcoreaddons+=		bin/*

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCOREADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcoreaddons
