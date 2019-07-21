# $NetBSD: buildlink3.mk,v 1.10 2019/07/21 22:23:58 wiz Exp $

BUILDLINK_TREE+=	lv2

.if !defined(LV2_BUILDLINK3_MK)
LV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lv2+=	lv2>=1.12.0
BUILDLINK_ABI_DEPENDS.lv2?=	lv2>=1.16.0nb3
BUILDLINK_PKGSRCDIR.lv2?=	../../audio/lv2

.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.endif	# LV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-lv2
