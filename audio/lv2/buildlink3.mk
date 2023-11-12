# $NetBSD: buildlink3.mk,v 1.24 2023/11/12 13:20:39 wiz Exp $

BUILDLINK_TREE+=	lv2

.if !defined(LV2_BUILDLINK3_MK)
LV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lv2+=	lv2>=1.12.0
BUILDLINK_ABI_DEPENDS.lv2+=	lv2>=1.18.10nb4
BUILDLINK_PKGSRCDIR.lv2?=	../../audio/lv2

.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.endif	# LV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-lv2
