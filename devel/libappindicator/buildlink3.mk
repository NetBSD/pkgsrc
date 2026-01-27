# $NetBSD: buildlink3.mk,v 1.31 2026/01/27 08:39:13 wiz Exp $

BUILDLINK_TREE+=	libappindicator

.if !defined(LIBAPPINDICATOR_BUILDLINK3_MK)
LIBAPPINDICATOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libappindicator+=	libappindicator>=12.10.0
BUILDLINK_ABI_DEPENDS.libappindicator+=	libappindicator>=12.10.0nb31
BUILDLINK_PKGSRCDIR.libappindicator?=	../../devel/libappindicator

.include "../../devel/libindicator/buildlink3.mk"
.include "../../devel/libdbusmenu-gtk3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBAPPINDICATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libappindicator
