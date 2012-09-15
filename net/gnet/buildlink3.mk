# $NetBSD: buildlink3.mk,v 1.14 2012/09/15 10:05:59 obache Exp $

BUILDLINK_TREE+=	gnet

.if !defined(GNET_BUILDLINK3_MK)
GNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnet+=	gnet>=2.0.3nb1
BUILDLINK_ABI_DEPENDS.gnet+=	gnet>=2.0.8nb4
BUILDLINK_PKGSRCDIR.gnet?=	../../net/gnet

.include "../../devel/glib2/buildlink3.mk"
.endif # GNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnet
