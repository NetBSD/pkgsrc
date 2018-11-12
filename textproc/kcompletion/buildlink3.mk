# $NetBSD: buildlink3.mk,v 1.11 2018/11/12 03:51:26 ryoon Exp $

BUILDLINK_TREE+=	kcompletion

.if !defined(KCOMPLETION_BUILDLINK3_MK)
KCOMPLETION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcompletion+=	kcompletion>=5.18.0
BUILDLINK_ABI_DEPENDS.kcompletion?=	kcompletion>=5.47.0nb3
BUILDLINK_PKGSRCDIR.kcompletion?=	../../textproc/kcompletion

.include "../../devel/kconfig/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCOMPLETION_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcompletion
