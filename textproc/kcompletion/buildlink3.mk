# $NetBSD: buildlink3.mk,v 1.1 2016/05/26 09:26:56 markd Exp $

BUILDLINK_TREE+=	kcompletion

.if !defined(KCOMPLETION_BUILDLINK3_MK)
KCOMPLETION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcompletion+=	kcompletion>=5.18.0
BUILDLINK_PKGSRCDIR.kcompletion?=	../../textproc/kcompletion

.include "../../devel/kconfig/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCOMPLETION_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcompletion
