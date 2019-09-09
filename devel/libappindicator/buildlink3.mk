# $NetBSD: buildlink3.mk,v 1.10 2019/09/09 12:59:06 nia Exp $

BUILDLINK_TREE+=	libappindicator

.if !defined(LIBAPPINDICATOR_BUILDLINK3_MK)
LIBAPPINDICATOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libappindicator+=	libappindicator>=12.10.0
BUILDLINK_ABI_DEPENDS.libappindicator+=	libappindicator>=12.10.0nb1
BUILDLINK_PKGSRCDIR.libappindicator?=	../../devel/libappindicator

.include "../../devel/libindicator3/buildlink3.mk"
.include "../../devel/libdbusmenu-gtk3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBAPPINDICATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libappindicator
