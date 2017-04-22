# $NetBSD: buildlink3.mk,v 1.5 2017/04/22 21:03:17 adam Exp $

BUILDLINK_TREE+=	kcompletion

.if !defined(KCOMPLETION_BUILDLINK3_MK)
KCOMPLETION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcompletion+=	kcompletion>=5.18.0
BUILDLINK_ABI_DEPENDS.kcompletion?=	kcompletion>=5.25.0nb6
BUILDLINK_PKGSRCDIR.kcompletion?=	../../textproc/kcompletion

.include "../../devel/kconfig/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCOMPLETION_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcompletion
