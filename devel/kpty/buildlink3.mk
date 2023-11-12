# $NetBSD: buildlink3.mk,v 1.30 2023/11/12 13:21:03 wiz Exp $

BUILDLINK_TREE+=	kpty

.if !defined(KPTY_BUILDLINK3_MK)
KPTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kpty+=	kpty>=5.19.0
BUILDLINK_ABI_DEPENDS.kpty?=	kpty>=5.108.0nb4
BUILDLINK_PKGSRCDIR.kpty?=	../../devel/kpty

.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KPTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-kpty
