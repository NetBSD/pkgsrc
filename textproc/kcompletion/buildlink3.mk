# $NetBSD: buildlink3.mk,v 1.29 2023/11/08 13:21:05 wiz Exp $

BUILDLINK_TREE+=	kcompletion

.if !defined(KCOMPLETION_BUILDLINK3_MK)
KCOMPLETION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcompletion+=	kcompletion>=5.18.0
BUILDLINK_ABI_DEPENDS.kcompletion?=	kcompletion>=5.108.0nb2
BUILDLINK_PKGSRCDIR.kcompletion?=	../../textproc/kcompletion

.include "../../devel/kconfig/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCOMPLETION_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcompletion
