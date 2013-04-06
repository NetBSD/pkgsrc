# $NetBSD: buildlink3.mk,v 1.3 2013/04/06 13:46:33 rodent Exp $

BUILDLINK_TREE+=	flow-tools

.if !defined(FLOW_TOOLS_BUILDLINK3_MK)
FLOW_TOOLS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.flow-tools?=	build

BUILDLINK_API_DEPENDS.flow-tools+=	flow-tools>=0.68nb2
BUILDLINK_PKGSRCDIR.flow-tools?=	../../net/flow-tools
.endif # FLOW_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-flow-tools
