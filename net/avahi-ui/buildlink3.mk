# $NetBSD: buildlink3.mk,v 1.4 2023/01/03 17:36:30 wiz Exp $

BUILDLINK_TREE+=	avahi-ui

.if !defined(AVAHI_UI_BUILDLINK3_MK)
AVAHI_UI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avahi-ui+=	avahi-ui>=0.8
BUILDLINK_ABI_DEPENDS.avahi-ui?=	avahi-ui>=0.8nb3
BUILDLINK_PKGSRCDIR.avahi-ui?=	../../net/avahi-ui

.include "../../x11/gtk3/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.endif	# AVAHI_UI_BUILDLINK3_MK

BUILDLINK_TREE+=	-avahi-ui
