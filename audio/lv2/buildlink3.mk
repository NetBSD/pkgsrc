# $NetBSD: buildlink3.mk,v 1.20 2023/04/17 17:43:48 adam Exp $

BUILDLINK_TREE+=	lv2

.if !defined(LV2_BUILDLINK3_MK)
LV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lv2+=	lv2>=1.12.0
BUILDLINK_ABI_DEPENDS.lv2+=	lv2>=1.18.4nb4
BUILDLINK_PKGSRCDIR.lv2?=	../../audio/lv2

.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.endif	# LV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-lv2
