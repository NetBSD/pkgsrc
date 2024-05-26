# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 11:14:36 markd Exp $

BUILDLINK_TREE+=	kf6-kbookmarks

.if !defined(KF6_KBOOKMARKS_BUILDLINK3_MK)
KF6_KBOOKMARKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kbookmarks+=	kf6-kbookmarks>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-kbookmarks?=	../../devel/kf6-kbookmarks

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../x11/kf6-kconfigwidgets/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KBOOKMARKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kbookmarks
