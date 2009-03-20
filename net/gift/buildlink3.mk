# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:25:08 joerg Exp $

BUILDLINK_TREE+=	gift

.if !defined(GIFT_BUILDLINK3_MK)
GIFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gift+=	gift>=0.11.6
BUILDLINK_ABI_DEPENDS.gift+=	gift>=0.11.6nb2
BUILDLINK_PKGSRCDIR.gift?=	../../net/gift

.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.endif # GIFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gift
