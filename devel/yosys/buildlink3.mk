# $NetBSD: buildlink3.mk,v 1.1 2025/12/25 16:39:27 ryoon Exp $

BUILDLINK_TREE+=	yosys

.if !defined(YOSYS_BUILDLINK3_MK)
YOSYS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.yosys?=	build

BUILDLINK_API_DEPENDS.yosys+=	yosys>=0.46nb2
BUILDLINK_PKGSRCDIR.yosys?=	../../devel/yosys

.include "../../lang/tcl/buildlink3.mk"
#.include "../../devel/boost-libs/buildlink3.mk"
#.include "../../devel/readline/buildlink3.mk"
#.include "../../devel/libffi/buildlink3.mk"
.endif	# YOSYS_BUILDLINK3_MK

BUILDLINK_TREE+=	-yosys
