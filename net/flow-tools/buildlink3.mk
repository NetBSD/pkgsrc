# $NetBSD: buildlink3.mk,v 1.4 2023/08/14 05:24:59 wiz Exp $

BUILDLINK_TREE+=	flow-tools

.if !defined(FLOW_TOOLS_BUILDLINK3_MK)
FLOW_TOOLS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.flow-tools?=	build

BUILDLINK_API_DEPENDS.flow-tools+=	flow-tools>=0.68nb2
BUILDLINK_ABI_DEPENDS.flow-tools?=	flow-tools>=0.68nb13
BUILDLINK_PKGSRCDIR.flow-tools?=	../../net/flow-tools
.endif # FLOW_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-flow-tools
