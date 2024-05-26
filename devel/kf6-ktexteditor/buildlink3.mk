# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 12:09:30 markd Exp $

BUILDLINK_TREE+=	kf6-ktexteditor

.if !defined(KF6_KTEXTEDITOR_BUILDLINK3_MK)
KF6_KTEXTEDITOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-ktexteditor+=	kf6-ktexteditor>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-ktexteditor?=	../../devel/kf6-ktexteditor

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../security/kf6-kauth/buildlink3.mk"
.include "../../textproc/kf6-sonnet/buildlink3.mk"
.include "../../textproc/kf6-syntax-highlighting/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/kf6-ktextwidgets/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KTEXTEDITOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-ktexteditor
