# $NetBSD: buildlink3.mk,v 1.5 2018/03/12 11:15:28 wiz Exp $

BUILDLINK_TREE+=	libappindicator

.if !defined(LIBAPPINDICATOR_BUILDLINK3_MK)
LIBAPPINDICATOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libappindicator+=	libappindicator>=12.10.0
BUILDLINK_ABI_DEPENDS.libappindicator?=	libappindicator>=12.10.0nb4
BUILDLINK_PKGSRCDIR.libappindicator?=	../../devel/libappindicator

.include "../../devel/libindicator/buildlink3.mk"
.include "../../devel/libdbusmenu-gtk/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# LIBAPPINDICATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libappindicator
