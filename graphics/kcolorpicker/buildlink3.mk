# $NetBSD: buildlink3.mk,v 1.2 2024/08/24 04:19:00 markd Exp $

BUILDLINK_TREE+=	kcolorpicker

.if !defined(KCOLORPICKER_BUILDLINK3_MK)
KCOLORPICKER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcolorpicker+=	kcolorpicker>=0.2.0
BUILDLINK_ABI_DEPENDS.kcolorpicker?=	kcolorpicker>=0.3.1
BUILDLINK_PKGSRCDIR.kcolorpicker?=	../../graphics/kcolorpicker

.endif	# KCOLORPICKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcolorpicker
