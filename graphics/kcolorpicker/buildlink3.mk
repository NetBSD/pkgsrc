# $NetBSD: buildlink3.mk,v 1.1 2022/09/29 00:08:22 markd Exp $

BUILDLINK_TREE+=	kcolorpicker

.if !defined(KCOLORPICKER_BUILDLINK3_MK)
KCOLORPICKER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcolorpicker+=	kcolorpicker>=0.2.0
BUILDLINK_PKGSRCDIR.kcolorpicker?=	../../graphics/kcolorpicker

.endif	# KCOLORPICKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcolorpicker
