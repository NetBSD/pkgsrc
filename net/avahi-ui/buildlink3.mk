# $NetBSD: buildlink3.mk,v 1.6 2023/10/21 17:11:09 gdt Exp $

BUILDLINK_TREE+=	avahi-ui

.if !defined(AVAHI_UI_BUILDLINK3_MK)
AVAHI_UI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.avahi-ui+=	avahi-ui>=0.8
BUILDLINK_ABI_DEPENDS.avahi-ui?=	avahi-ui>=0.8nb5
BUILDLINK_PKGSRCDIR.avahi-ui?=	../../net/avahi-ui

.include "../../x11/gtk3/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.endif	# AVAHI_UI_BUILDLINK3_MK

BUILDLINK_TREE+=	-avahi-ui
