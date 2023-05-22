# $NetBSD: buildlink3.mk,v 1.26 2023/05/22 21:00:04 wiz Exp $

BUILDLINK_TREE+=	kunitconversion

.if !defined(KUNITCONVERSION_BUILDLINK3_MK)
KUNITCONVERSION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kunitconversion+=	kunitconversion>=5.19.0
BUILDLINK_ABI_DEPENDS.kunitconversion?=	kunitconversion>=5.98.0nb5
BUILDLINK_PKGSRCDIR.kunitconversion?=	../../misc/kunitconversion

.include "../../devel/ki18n/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KUNITCONVERSION_BUILDLINK3_MK

BUILDLINK_TREE+=	-kunitconversion
