# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:45 joerg Exp $

BUILDLINK_TREE+=	silgraphite

.if !defined(SILGRAPHITE_BUILDLINK3_MK)
SILGRAPHITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.silgraphite+=	silgraphite>=2.3
BUILDLINK_PKGSRCDIR.silgraphite?=	../../graphics/silgraphite
.endif # SILGRAPHITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-silgraphite
