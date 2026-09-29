# $NetBSD: buildlink3.mk,v 1.19 2026/09/29 06:06:59 wiz Exp $

BUILDLINK_TREE+=	gnet1

.if !defined(GNET1_BUILDLINK3_MK)
GNET1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnet1+=	gnet1>=1.1.8nb2
BUILDLINK_ABI_DEPENDS.gnet1+=	gnet1>=1.1.8nb14
BUILDLINK_PKGSRCDIR.gnet1?=	../../net/gnet1

.include "../../devel/glib2/buildlink3.mk"
.endif # GNET1_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnet1
