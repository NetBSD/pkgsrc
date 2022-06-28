# $NetBSD: buildlink3.mk,v 1.11 2022/06/28 11:35:00 wiz Exp $

BUILDLINK_TREE+=	gift

.if !defined(GIFT_BUILDLINK3_MK)
GIFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gift+=	gift>=0.11.6
BUILDLINK_ABI_DEPENDS.gift+=	gift>=0.11.8.1nb14
BUILDLINK_PKGSRCDIR.gift?=	../../net/gift

.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.endif # GIFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gift
