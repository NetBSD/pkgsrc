# $NetBSD: buildlink3.mk,v 1.7 2025/10/23 20:39:34 wiz Exp $

BUILDLINK_TREE+=	kf6-syntax-highlighting

.if !defined(KF6_SYNTAX_HIGHLIGHTING_BUILDLINK3_MK)
KF6_SYNTAX_HIGHLIGHTING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-syntax-highlighting+=	kf6-syntax-highlighting>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-syntax-highlighting?=	kf6-syntax-highlighting>=6.18.0nb1
BUILDLINK_PKGSRCDIR.kf6-syntax-highlighting?=	../../textproc/kf6-syntax-highlighting

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_SYNTAX_HIGHLIGHTING_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-syntax-highlighting
