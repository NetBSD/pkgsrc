# $NetBSD: buildlink3.mk,v 1.3 2025/12/21 12:10:01 markd Exp $

BUILDLINK_TREE+=	kcolorpicker

.if !defined(KCOLORPICKER_BUILDLINK3_MK)
KCOLORPICKER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcolorpicker+=	kcolorpicker>=0.2.0
BUILDLINK_ABI_DEPENDS.kcolorpicker?=	kcolorpicker>=0.3.1nb7
BUILDLINK_PKGSRCDIR.kcolorpicker?=	../../graphics/kcolorpicker

.endif	# KCOLORPICKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcolorpicker
