# $NetBSD: buildlink3.mk,v 1.1 2024/05/26 13:06:41 markd Exp $

BUILDLINK_TREE+=	kf6-ktexttemplate

.if !defined(KF6_KTEXTTEMPLATE_BUILDLINK3_MK)
KF6_KTEXTTEMPLATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-ktexttemplate+=	kf6-ktexttemplate>=6.2.0
BUILDLINK_PKGSRCDIR.kf6-ktexttemplate?=		../../textproc/kf6-ktexttemplate

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KTEXTTEMPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-ktexttemplate
