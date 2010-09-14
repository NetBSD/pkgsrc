# $NetBSD: buildlink3.mk,v 1.16 2010/09/14 11:01:04 wiz Exp $

BUILDLINK_TREE+=	totem

.if !defined(TOTEM_BUILDLINK3_MK)
TOTEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.totem+=	{totem,totem-xine}>=1.4.0
BUILDLINK_ABI_DEPENDS.totem+=	totem>=2.30.2nb3
BUILDLINK_PKGSRCDIR.totem?=	../../multimedia/totem

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # TOTEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-totem
