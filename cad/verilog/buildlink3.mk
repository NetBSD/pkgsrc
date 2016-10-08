# $NetBSD: buildlink3.mk,v 1.11 2016/10/08 22:30:43 kamil Exp $

BUILDLINK_TREE+=	verilog

.if !defined(VERILOG_BUILDLINK3_MK)
VERILOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.verilog+=	verilog>=10.1.1
BUILDLINK_PKGSRCDIR.verilog?=	../../cad/verilog

.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.endif	# VERILOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-verilog
