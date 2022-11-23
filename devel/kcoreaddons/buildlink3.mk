# $NetBSD: buildlink3.mk,v 1.25 2022/11/23 16:18:39 adam Exp $

BUILDLINK_TREE+=	kcoreaddons

.if !defined(KCOREADDONS_BUILDLINK3_MK)
KCOREADDONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcoreaddons+=	kcoreaddons>=5.18.0
BUILDLINK_ABI_DEPENDS.kcoreaddons?=	kcoreaddons>=5.98.0nb1
BUILDLINK_PKGSRCDIR.kcoreaddons?=	../../devel/kcoreaddons

BUILDLINK_FILES.kcoreaddons+=		bin/*

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCOREADDONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcoreaddons
