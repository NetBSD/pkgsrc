# $NetBSD: buildlink3.mk,v 1.1 2025/11/02 09:59:20 markd Exp $

BUILDLINK_TREE+=	kf6-kuserfeedback

.if !defined(KF6_KUSERFEEDBACK_BUILDLINK3_MK)
KF6_KUSERFEEDBACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kuserfeedback+=	kf6-kuserfeedback>=6.18.0
BUILDLINK_PKGSRCDIR.kf6-kuserfeedback?=		../../misc/kf6-kuserfeedback

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KUSERFEEDBACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kuserfeedback
