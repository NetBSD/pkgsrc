# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:25:06 joerg Exp $

BUILDLINK_TREE+=	totem

.if !defined(TOTEM_BUILDLINK3_MK)
TOTEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.totem+=	{totem,totem-xine}>=1.4.0
BUILDLINK_ABI_DEPENDS.totem+=	{totem,totem-xine}>=2.20.3nb2
BUILDLINK_PKGSRCDIR.totem?=	../../multimedia/totem

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # TOTEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-totem
