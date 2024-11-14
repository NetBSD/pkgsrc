# $NetBSD: buildlink3.mk,v 1.4 2024/11/14 22:21:51 wiz Exp $

BUILDLINK_TREE+=	kf6-syntax-highlighting

.if !defined(KF6_SYNTAX_HIGHLIGHTING_BUILDLINK3_MK)
KF6_SYNTAX_HIGHLIGHTING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-syntax-highlighting+=	kf6-syntax-highlighting>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-syntax-highlighting?=	kf6-syntax-highlighting>=6.2.0nb4
BUILDLINK_PKGSRCDIR.kf6-syntax-highlighting?=	../../textproc/kf6-syntax-highlighting

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_SYNTAX_HIGHLIGHTING_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-syntax-highlighting
