# $NetBSD: buildlink3.mk,v 1.26 2023/05/22 20:59:56 wiz Exp $

BUILDLINK_TREE+=	kcrash

.if !defined(KCRASH_BUILDLINK3_MK)
KCRASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcrash+=	kcrash>=5.18.0
BUILDLINK_ABI_DEPENDS.kcrash?=	kcrash>=5.98.0nb5
BUILDLINK_PKGSRCDIR.kcrash?=	../../devel/kcrash

.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../x11/kwindowsystem/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCRASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcrash
