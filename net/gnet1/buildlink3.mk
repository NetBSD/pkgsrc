# $NetBSD: buildlink3.mk,v 1.14 2012/09/15 10:05:59 obache Exp $

BUILDLINK_TREE+=	gnet1

.if !defined(GNET1_BUILDLINK3_MK)
GNET1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnet1+=	gnet1>=1.1.8nb2
BUILDLINK_ABI_DEPENDS.gnet1+=	gnet1>=1.1.8nb8
BUILDLINK_PKGSRCDIR.gnet1?=	../../net/gnet1

.include "../../devel/glib2/buildlink3.mk"
.endif # GNET1_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnet1
