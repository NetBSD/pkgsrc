# $NetBSD: buildlink3.mk,v 1.2 2020/03/08 16:47:51 wiz Exp $

BUILDLINK_TREE+=	wld

.if !defined(WLD_BUILDLINK3_MK)
WLD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wld+=	wld>=0.0.0.20191211
BUILDLINK_ABI_DEPENDS.wld?=	wld>=0.0.0.20200220nb1
BUILDLINK_PKGSRCDIR.wld?=	../../graphics/wld

.include "../../devel/wayland/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.endif	# WLD_BUILDLINK3_MK

BUILDLINK_TREE+=	-wld
