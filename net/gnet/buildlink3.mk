# $NetBSD: buildlink3.mk,v 1.12 2012/02/06 12:41:11 wiz Exp $

BUILDLINK_TREE+=	gnet

.if !defined(GNET_BUILDLINK3_MK)
GNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnet+=	gnet>=2.0.3nb1
BUILDLINK_ABI_DEPENDS.gnet+=	gnet>=2.0.8nb2
BUILDLINK_PKGSRCDIR.gnet?=	../../net/gnet

.include "../../devel/glib2/buildlink3.mk"
.endif # GNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnet
