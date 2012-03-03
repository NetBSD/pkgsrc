# $NetBSD: buildlink3.mk,v 1.13 2012/03/03 00:12:05 wiz Exp $

BUILDLINK_TREE+=	gnet1

.if !defined(GNET1_BUILDLINK3_MK)
GNET1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnet1+=	gnet1>=1.1.8nb2
BUILDLINK_ABI_DEPENDS.gnet1+=	gnet1>=1.1.8nb7
BUILDLINK_PKGSRCDIR.gnet1?=	../../net/gnet1

.include "../../devel/glib2/buildlink3.mk"
.endif # GNET1_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnet1
