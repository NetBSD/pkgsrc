# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:08 joerg Exp $

BUILDLINK_DEPMETHOD.flow-tools?=	build

BUILDLINK_TREE+=	flow-tools

.if !defined(FLOW_TOOLS_BUILDLINK3_MK)
FLOW_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flow-tools+=	flow-tools>=0.68nb2
BUILDLINK_PKGSRCDIR.flow-tools?=	../../net/flow-tools
.endif # FLOW_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-flow-tools
